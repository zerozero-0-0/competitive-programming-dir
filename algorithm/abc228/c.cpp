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

  int n, k;
  cin >> n >> k;
  vector p(n, vector<int> (3));
  rep(i, n) rep(j, 3) cin >> p[i][j];

  vector<int> sum(n, 0);
  rep(i, n) {
    rep(j, 3) sum[i] += p[i][j];
  }

  auto vec = sum;
  sort(vec.rbegin(), vec.rend());
  int norm = vec[k - 1];

  rep(i, n) {
    int score = sum[i] + 300;
    if (score >= norm) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }
}
