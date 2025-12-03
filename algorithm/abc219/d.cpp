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

  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector dp(n + 1, vector<vector<int>> (n + 1, vector<int> (x + 1, -iinf)));

  // dp[i][j][k] := i番目まで見て、j個弁当を買ったとき、たこやきがk個のときのたい焼きの最大値

  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= x; ++k) {
        if (dp[i][j][k] == -iinf) continue;
        // i番目を買う場合
        int idx_k = min(x, k + a[i]);
        dp[i + 1][j + 1][idx_k] = max(dp[i + 1][j + 1][idx_k], dp[i][j][k] + b[i]);
        // i番目を買わない場合
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
      }
    }
  }

  int ans = -1;
  rep(j, n + 1) {
    if (dp[n][j][x] >= y) ans = j;
    if (ans != -1) break;
  }
  
  cout << ans << "\n";
}
