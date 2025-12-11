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

  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  rep(i, h) cin >> c[i];

  vector dist(h, vector<int> (w, -1));

  auto dfs = [&](auto dfs, int i, int j, int d) {
    if (dist[i][j] != -1) return ;
    dist[i][j] = d;
    int ni = i + 1, nj = j + 1;
    if (ni < h && c[ni][j] == '.') {
      dfs(dfs, ni, j, d + 1);
    }
    if (nj < w && c[i][nj] == '.') {
      dfs(dfs, i, nj, d + 1);
    }
  };

  dfs(dfs, 0, 0, 0);

  int me = 0;
  rep(i, h) rep(j, w) me = max(me, dist[i][j]);

  cout << me + 1 << "\n";
}
