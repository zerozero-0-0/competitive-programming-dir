#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> k(m);
  vector<deque<int>> a(m);

  rep(i, m) {
    cin >> k[i];
    a[i].resize(k[i]);
    rep(j, k[i]) {
      cin >> a[i][j];
    }
  }

  // 球を取り出したときその球のインデックスは簡単に求められる
  // そこのインデックスの奴だけを更新すれば1ループあたり2回だけでいい

  vector<vector<int>> idx(n + 1, vector<int> (2, -1));
  // idx[i] := 球iがある筒のインデックス
  rep(i, m) {
    rep(j, k[i]) {
      if (idx[a[i][j]][0] == -1) idx[a[i][j]][0] = i;
      else idx[a[i][j]][1] = i;
    }
  }

  vector<int> cnt(n + 1); // cnt[i] := 筒の一番上にある球iの個数
  rep(i, m) {
    cnt[a[i][0]]++;
  }

  queue<int> que;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] == 2) {
      que.emplace(i);
    }
  }

  int sum = 0;
  while (que.size()) {
    int num = que.front();
    que.pop();
    sum++;

    int first = idx[num][0], second = idx[num][1];

    a[first].pop_front();
    if (a[first].size() > 0) {
      cnt[a[first][0]]++;
      if (cnt[a[first][0]] == 2) que.emplace(a[first][0]);
    }
    a[second].pop_front();
    if (a[second].size() > 0) {
      cnt[a[second][0]]++;
      if (cnt[a[second][0]] == 2) que.emplace(a[second][0]);
    }
  }

  if (sum != n) cout << "No" << "\n";
  else cout << "Yes" << "\n";
}
