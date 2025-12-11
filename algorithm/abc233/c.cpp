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

  int n; ll x;
  cin >> n >> x;

  vector<int> l(n);
  vector<vector<int>> a(n);
  rep(i, n) {
    cin >> l[i];
    a[i].resize(l[i]);
    rep(j, l[i]) cin >> a[i][j];
  }

  int ans = 0;
  auto solve = [&](auto solve, int idx, ll cur) {
    if (idx == n && cur == 1) {
      ++ans;
      return ;
    } else if (idx == n) return ;
    for (auto i : a[idx]) {
      if (cur % i == 0) solve(solve, idx + 1, cur / i);
    }
  };

  solve(solve, 0, x);

  cout << ans << "\n";
}
