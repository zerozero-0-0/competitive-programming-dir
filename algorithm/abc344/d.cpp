#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int iinf = 1e9;
const ll linf = LONG_LONG_MAX;

int main() {
  string t;
  int n;
  cin >> t >> n;
  vector<int> a(n);
  vector<vector<string>> s(n);

  rep(i, n) {
    cin >> a[i];
    s[i].resize(a[i]);
    for (auto &cs : s[i]) cin >> cs;
  }

  int m = t.size();
  vector dp(n + 1, vector<int>(m + 1, iinf));
  // dp[i][j] := i番目まで見た時のtの1 ~ t 番目まで作るための最小コスト
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {

    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
    }

    for (auto cs : s[i - 1]) {
      int len = cs.size();
      for (int l = 0; l + len <= m; l++) {
        string st = t.substr(l, len);

        if (dp[i - 1][l] != iinf) {
          if (st == cs) {
            dp[i][l + len] = min(dp[i][l + len], dp[i - 1][l] + 1);
          }
        }
      }
    }
  }

  if (dp[n][m] == iinf)
    cout << -1 << "\n";
  else
    cout << dp[n][m] << endl;
}
