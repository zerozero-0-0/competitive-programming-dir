#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);

  int n;
  cin >> n;
  vector<double> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<double> t(n);
  rep(i, n) t[i] = a[i] / b[i];

  double T = accumulate(t.begin(), t.end(), 0.0);

  double ct = T / 2;
  double ans = 0.0;

  int idx = 0;
  while (ct > 0) {
    if (t[idx] > ct) {
      ans += b[idx] * ct;
      ct = 0;
    } else {
      ans += a[idx];
      ct -= t[idx];
    }

    idx++;
  }

  cout << ans << "\n";
}
