#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int main() {
  int n, m;
  cin >> n >> m;
  vector a(m, vector<int> (n));
  for (auto & i : a) for (auto &j : i) cin >> j;

  vector dp(m + 1, vector<int> ((1 << n) + 1, inf));
  dp[0][0] = 0;

  const int bits = 1 << n;
  for (int i = 1; i <= m; i++) {
    for (int bit = 0; bit <= bits; bit++) {
      vector<bool> have(n + 1, false);
      for (int j = 1; j <= n; j++) {
        if (bit & (1 << (j - 1))) have[j] = true;
      }

      int v = 0;
      for (int j = 1; j < n; j++) {
        
      }
    }
  }
}
