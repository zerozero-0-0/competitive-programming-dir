#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
constexpr int iinf = INT_MAX;
constexpr long long linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  vector<vector<int>> rG(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    rG[y].push_back(x);
  }

  vector<bool> isReachable(n);

  auto dfs = [&](auto dfs, int u) {
    if (isReachable[u]) return ;
    isReachable[u] = true;
    for (auto v : rG[u]) {
      dfs(dfs, v);
    }
  };

  int q;
  cin >> q;
  while (q--) {
    int op, v;
    cin >> op >> v;
    --v;
    if (op == 1) {
      dfs(dfs, v);
    } else {
      if (isReachable[v]) cout << "Yes" << "\n";
      else cout << "No" << "\n";
    }
  }
}
