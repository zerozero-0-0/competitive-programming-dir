#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
constexpr int iinf = INT_MAX;
constexpr long long linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  auto solve = [&]() {
    int n, h;
    cin >> n >> h;
    vector<int> t(n), l(n), u(n);
    rep(i, n) cin >> t[i] >> l[i] >> u[i];

    vector<int> uh(n), bh(n);
    int ch = h;
    int dt, nuh, nbh;
    rep(i, n) {
      if (i == 0) {
        dt = t[i];
        nuh = ch + dt;
        nbh = ch - dt;

      } else {
        dt = t[i] - t[i - 1];
        nuh = uh[i - 1] + dt;
        nbh = bh[i - 1] - dt;
      }
      
      if (nuh < l[i] || nbh > u[i]) return false;
      uh[i] = min(u[i], nuh);
      bh[i] = max(l[i], nbh);
    }

    return true;
  };

  while (t--) {
    bool flg = solve();
    if (flg)
      cout << "Yes" << "\n";
    else
      cout << "No" << "\n";
  }
}
