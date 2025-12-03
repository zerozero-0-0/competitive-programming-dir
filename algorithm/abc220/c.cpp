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
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) cin >> i;
  ll x;
  cin >> x;
  ll ans = 0;

  ll sum = accumulate(a.begin(), a.end(), 0LL);

  ll s = x / sum;
  x %= sum;

  ans += n * s;
  for (int i = 0; i < n && x >= 0; i++) {
    x -= a[i];
    ans++;
  }

  cout << ans << endl;
}
