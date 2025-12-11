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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &i : a) cin >> i;

  vector<ll> sum(n);
  sum[0] = a[0];
  rep(i, n - 1) sum[i + 1] = sum[i] + a[i + 1];

  map<ll, int> mp;

  ll ans = 0;
  ll cur = 0;
  mp[0]++;

  rep(l, n) {
    cur = sum[l];
    ans += mp[cur - k];
    mp[cur]++;
  }

  cout << ans << "\n";
}
