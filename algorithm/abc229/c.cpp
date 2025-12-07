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

  int n;
  ll w;
  cin >> n >> w;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  ll ans = 0;
  vector<pair<ll, ll>> vec(n);
  rep(i, n) vec[i] = {a[i], b[i]};

  sort(vec.rbegin(), vec.rend());

  for (auto [a, b] : vec) {
    if (w == 0) continue;
    if (b > w) {
      ans += a * w;
      w = 0;
    } else {
      ans += a * b;
      w -= b;
    }
  }

  cout << ans << "\n";
}
