#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  vector dp (n + 1, vector<mint> (3009));
  // dp[i][j] := i番目まで見てjになる個数
  dp[0][0] = 1;

  rep(i, n + 1) {
    rep(j, 3000) dp[i][j + 1] += dp[i][j];
    if (i < n) {
      for (int j = a[i]; j <= b[i]; ++j) dp[i + 1][j] += dp[i][j];
    }
  }

  cout << dp[n][3000].val() << "\n";
}
