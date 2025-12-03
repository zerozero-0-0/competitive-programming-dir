#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

struct node {
  double x, y;
  double vx, vy;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int _;
  rep(i, 4) cin >> _;

  constexpr int n = 300, t = 1000, m = 10, k = 30, l = 1e5;

  // n : 点の総数
  // t : 総ステップ数
  // m : 目標連結成分数
  // k : 目標サイズ
  // l : 空間の一辺

  vector<node> nodes(n);
  vector<int> parent(n);
  vector<int> size(n, 1);

  auto find = [&](auto find, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(find, parent[x]);
  };
  
  // トーラス上の距離計算
  auto calc_dist = [&](double x1, double y1, double x2, double y2) -> double {
    double dx = abs(x1 - x2);
    double dy = abs(y1 - y2);
    dx = min(dx, l - dx);
    dy = min(dy, l - dy);
    return round(sqrt(dx * dx + dy * dy));
  };
  
  // 時刻tでの位置を予測
  auto predict_pos = [&](int idx, int time) -> pair<double, double> {
    double px = nodes[idx].x + nodes[idx].vx * time;
    double py = nodes[idx].y + nodes[idx].vy * time;
    px = fmod(px, l);
    if (px < 0) px += l;
    py = fmod(py, l);
    if (py < 0) py += l;
    return {px, py};
  };
  
  rep(i, n) {
    parent[i] = i;
    cin >> nodes[i].x >> nodes[i].y >> nodes[i].vx >> nodes[i].vy;
  }

  auto init = [&]() {
    // とりあえず1個ずつ連結させてく
    for (int i = 0; i < m; ++i) {
      int top = i * k;
      for (int t = 0; t < k - 1; ++t) {
        int u = top + t;
        int v = top + t + 1;
        println("{} {} {}", 0, u, v);
      }
    }
  };

  auto move = [&]() {
    for (auto& node : nodes) {
      node.x += node.vx;
      node.y += node.vy;

      node.x = fmod(node.x, l);
      if(node.x < 0) node.x += l;
      node.y = fmod(node.y, l);
      if(node.y < 0) node.y += l;
    }
  };

  auto assemble = [&](int i, int j) {
    int root_i = find(find, i);
    int root_j = find(find, j);
    
    if (root_i == root_j) return false; // 既に同じ連結成分
    
    // 連結成分 A (root_i) と B (root_j) のサイズ
    int size_a = size[root_i];
    int size_b = size[root_j];
    
    // 連結成分 A と B の速度
    double vx_a = nodes[root_i].vx;
    double vy_a = nodes[root_i].vy;
    double vx_b = nodes[root_j].vx;
    double vy_b = nodes[root_j].vy;
    
    // 運動量保存則に従った新しい速度
    double vx_new = (size_a * vx_a + size_b * vx_b) / (size_a + size_b);
    double vy_new = (size_a * vy_a + size_b * vy_b) / (size_a + size_b);
    
    // Union-Find で結合
    parent[root_j] = root_i;
    size[root_i] += size[root_j];
    
    // 連結成分全体の速度を更新
    rep(idx, n) {
      if (find(find, idx) == root_i) {
        nodes[idx].vx = vx_new;
        nodes[idx].vy = vy_new;
      }
    }
    return true;
  };
  
  // 優先度付きキュー: (コスト, 時刻, i, j)
  priority_queue<tuple<double, int, int, int>, 
                 vector<tuple<double, int, int, int>>,
                 greater<tuple<double, int, int, int>>> pq;
  
  // 全時刻・全ペアのコストを事前計算してキューに追加（初期バッチ）
  rep(time, min(100, t)) { // 最初の100時刻分を計算
    rep(i, n) {
      rep(j, i) {
        auto [xi, yi] = predict_pos(i, time);
        auto [xj, yj] = predict_pos(j, time);
        double cost = calc_dist(xi, yi, xj, yj);
        pq.push({cost, time, i, j});
      }
    }
  }
  
  vector<tuple<int, int, int>> operations; // (time, i, j)
  int current_time = 0;
  
  // 安全ガード: 実行時間/無限ループ対策
  int safe_iters = 0;
  while ((int)operations.size() < n - m && current_time < t) {
    if (++safe_iters > 200000) break; // 早期打ち切りガード
    if (pq.empty()) {
      // キューが空なら、次の時刻分を補充
      int add_from = current_time;
      if (add_from >= t) break;
      rep(dt, min(10, t - add_from)) { // 10時刻分だけ軽く補充
        int time = add_from + dt;
        // 代表ノード同士のみ候補化して計算量削減
        vector<int> reps;
        reps.reserve(n);
        rep(i, n) {
          int ri = find(find, i);
          if (i == ri) reps.push_back(i);
        }
        int R = reps.size();
        rep(a, R) rep(b, a) {
          int i = reps[a], j = reps[b];
          auto [xi, yi] = predict_pos(i, time);
          auto [xj, yj] = predict_pos(j, time);
          double cost = calc_dist(xi, yi, xj, yj);
          pq.push({cost, time, i, j});
        }
      }
      if (pq.empty()) break;
    }
    auto [cost, time, i, j] = pq.top();
    pq.pop();
    
    // 時刻を進める
    while (current_time < time) {
      move();
      current_time++;
    }
    
    // 異なる連結成分かつサイズ制約をチェック
    int root_i = find(find, i);
    int root_j = find(find, j);
    if (root_i != root_j && size[root_i] + size[root_j] <= k) {
      operations.push_back({time, i, j});
      assemble(i, j);
      continue;
    }

    // 取り出した候補が不適なら、その時刻で代表ノード同士から有効最小コストペアを探索
    double best_cost = 1e18;
    int bi = -1, bj = -1;
    vector<int> reps;
    reps.reserve(n);
    rep(a, n) if (a == find(find, a)) reps.push_back(a);
    int R = reps.size();
    // 制限付き探索で計算量を抑制（上位一部のみ）
    for (int a = 0; a < R; ++a) {
      for (int b = 0; b < a; ++b) {
        int ra = reps[a];
        int rb = reps[b];
        if (ra == rb) continue;
        if (size[ra] + size[rb] > k) continue;
        auto [xa, ya] = predict_pos(ra, time);
        auto [xb, yb] = predict_pos(rb, time);
        double c = calc_dist(xa, ya, xb, yb);
        if (c < best_cost) { best_cost = c; bi = ra; bj = rb; }
      }
    }
    if (bi != -1) {
      operations.push_back({time, bi, bj});
      assemble(bi, bj);
      continue;
    }
    // それでも見つからない場合は時刻を進めて続行
    if (current_time < t) {
      move();
      current_time++;
    }
  }
  
  // 出力
  // 行数が不足している場合のフォールバック: サイズ制約を緩めて充足させる（注意: 無効出力の可能性）
  while ((int)operations.size() < n - m) {
    int time = min(current_time, t - 1);
    // 代表ノード同士から最小コストペアを選ぶ（サイズ制約なし）
    vector<int> reps;
    reps.reserve(n);
    rep(a, n) if (a == find(find, a)) reps.push_back(a);
    int R = reps.size();
    if (R < 2) break;
    double best_cost = 1e18; int bi = -1, bj = -1;
    for (int a = 0; a < R; ++a) {
      for (int b = 0; b < a; ++b) {
        int ra = reps[a], rb = reps[b];
        if (ra == rb) continue;
        auto [xa, ya] = predict_pos(ra, time);
        auto [xb, yb] = predict_pos(rb, time);
        double c = calc_dist(xa, ya, xb, yb);
        if (c < best_cost) { best_cost = c; bi = ra; bj = rb; }
      }
    }
    if (bi == -1) break;
    operations.push_back({time, bi, bj});
    assemble(bi, bj); // サイズ制約を超える可能性あり
  }

  for (auto [time, i, j] : operations) {
    cout << time << " " << i << " " << j << "\n";
  }
  

}
