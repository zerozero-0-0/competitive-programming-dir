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
  vector<string> s(n), t(n);
  for (auto &i : s) cin >> i;
  for (auto &i : t) cin >> i;

  auto rot = [&](vector<string> t) {
    vector res(n, string (n, '.'));
    rep(i, n) rep(j, n) {
      res[j][n - 1 - i] = t[i][j];
    }

    return res;
  };

  auto normalize = [&](vector<string> t) {
    int li = n, lj = n;
    rep(i, n) rep(j, n) {
      if (t[i][j] == '#') {
        li = min(li, i);
        lj = min(lj, j);
      }
    }

    vector res(n, string (n, '.'));
    rep(i, n) rep(j, n) if (t[i][j] == '#') {
      res[i - li][j - lj] = '#';
    }

    return res;
  };

  auto same = [&](vector<string> s, vector<string> t) {
    return normalize(s) == normalize(t); 
  };

  rep(i, 4) {
    if (same(s, t)) {
      cout << "Yes" << "\n";
      return 0;
    }
    t = rot(t);
  }

  cout << "No" << "\n";
}
