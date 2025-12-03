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

  cout << fixed << setprecision(20);

  int n;
  cin >> n;
  vector<double> a(n), b(n);
  vector<double> t(n);

  rep(i, n) {
    cin >> a[i] >> b[i];
    t[i] = a[i] / b[i];
  }

  rep(i, n - 1) t[i + 1] += t[i];

  double left = -1, right = t[n - 1];
  while (right - left > 1.0) {
    double mid = left + (right - left) / 2;
    double l = t[mid], r = t[n - 1] - t[mid];

    if (l < r) left = mid;
    else right = mid;
  }

  double ans = 0.0;
  rep(i, n) {
    if (left < t[i]) ans += b[i] * left;
    else ans += a[i], left -= t[i];
  }

  cout << ans << "\n";
}
