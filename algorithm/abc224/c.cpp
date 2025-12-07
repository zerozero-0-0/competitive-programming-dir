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

  ll n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    vec[i] = {x, y};
  }

  ll ans = n * (n - 1) * (n - 2) / 6;

  rep(i, n) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        // 3点が一直線上だったらアウト
        ll l = (vec[i].first - vec[j].first) * (vec[i].second - vec[k].second);
        ll r = (vec[i].second - vec[j].second) * (vec[i].first - vec[k].first);

        if (l == r) --ans;
      }
    }
  }

  cout << ans << "\n";
}
