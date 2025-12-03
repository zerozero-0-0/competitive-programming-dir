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

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  map<int, vector<double>> mp;
  rep(i, n) {
    mp[a[i]].push_back(b[i]);
  }

  for (int k = 1; k <= m; ++k) {
    double ans = (double)accumulate(mp[k].begin(), mp[k].end(), 0) / mp[k].size();
    cout << fixed << setprecision(20) << ans << "\n";
  }

}
