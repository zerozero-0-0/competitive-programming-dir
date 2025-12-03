#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
constexpr int iinf = INT_MAX;
constexpr long long linf = LONG_LONG_MAX;

using mint = modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  vector vec(n, vector<modint> (10, 0));
  vec[0][a[0]] = 1;

  for (int i = 0; i < n - 1; i++) {
    rep(j, 10) {
      int f = (a[i + 1] + j) % 10;
      int g = (a[i + 1] * j) % 10;
      vec[i + 1][f] += vec[i][j];
      vec[i + 1][g] += vec[i][j];
    }
  }

  rep(k, 10) {
    cout << vec[n - 1][k].val() << "\n";
  }
}
