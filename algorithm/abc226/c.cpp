#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> t(n), k(n);
  vector<vector<int>> a(n);
  rep(i, n) {
    cin >> t[i] >> k[i];
    a[i].resize(k[i]);
    rep(j, k[i]) {
      cin >> a[i][j];
      --a[i][j];
    }
  }

  vector<bool> isUsed(n);
  isUsed[n - 1] = true;
  for (int i = n - 1; i >= 0; --i) {
    if (!isUsed[i]) continue;
    for (auto j : a[i]) {
      isUsed[j] = true;
    }
  }

  ll ans = 0;
  rep(i, n) if (isUsed[i]) ans += t[i];
  cout << ans << "\n";
}
