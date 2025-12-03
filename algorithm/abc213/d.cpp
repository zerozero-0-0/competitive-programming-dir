#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> G(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (auto &i : G) {
    sort(i.begin(), i.end());
  }

  auto dfs = [&](auto dfs, int i, int p = -1) -> void {
    cout << i + 1 << "\n";
    for (int nx : G[i]) {
      if (nx == p) continue;
      dfs(dfs, nx, i);
      cout << i + 1 << "\n";
    }
  };

  dfs(dfs, 0);
}
