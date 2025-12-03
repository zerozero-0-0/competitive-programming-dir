#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<pair<ll, bool>> vec;
  rep(i, n) {
    vec.push_back({a[i], true});
    vec.push_back({a[i] + b[i], false});
  }

  sort(vec.begin(), vec.end());
  map<ll, ll> mp;

  ll now = 0;
  for (int i = 0; i < 2 * n - 1; ++i) {
    ll dd = vec[i + 1].first - vec[i].first;

    if (vec[i].second) {
      now++;
    } else {
      now--;
    }
    mp[now] += dd;
  }
  for (int k = 1; k <= n; ++k) {
    cout << mp[k] << "\n";
  }
}
