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

  ll n;
  cin >> n;
  vector<int> u(n), d(n), l(n), r(n);
  rep(i, n) cin >> u[i] >> d[i] >> l[i] >> r[i];

  ll sum = 2000 * 2000;
  const int m = 2000;
  // n * nの配列を持って累積和
  vector grid(m + 2, vector<int> (m + 2));

  rep(i, n) {
    grid[u[i]][l[i]]++;
    grid[u[i]][r[i] + 1]--;
    grid[d[i] + 1][l[i]]--;
    grid[d[i] + 1][r[i] + 1]++;
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      grid[i + 1][j] += grid[i][j];
    }
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      grid[i][j + 1] += grid[i][j];
    }
  }

  // なんかしらの雲に覆われている点の個数
  ll isCovered = 0;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (grid[i][j] != 0) isCovered++;
    }
  }

  vector plus(m + 2, vector<int> (m + 2, 0));
  // plus[r] := 0 ~ rまでの1の個数
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (grid[i][j] == 1) plus[i][j] = 1;
    }
  }

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      plus[i][j + 1] += plus[i][j];
    }
  }

  // for (int i = 0; i < 10; i++) {
  //   for (int j = 0; j < 10; j++) {
  //     print("{}", plus[i][j]);
  //   }
  //   println();
  // }

  

  rep(k, n) {
    ll ans = 0;
    for (int i = u[k]; i <= d[k]; ++i) {
      int a = plus[i][r[k]] - plus[i][l[k] - 1];
    // println("{}", a);
      ans += (plus[i][r[k]] - plus[i][l[k] - 1]);
    }

    println("{}", sum - isCovered + ans);
  }
}
