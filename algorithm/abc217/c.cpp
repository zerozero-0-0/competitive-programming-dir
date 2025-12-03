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
  vector<int> p(n);
  for (auto &i : p) cin >> i;

  vector<int> q(n);
  rep(i, n) {
    q[p[i] - 1] = i + 1;
  }

  for (auto i : q) cout << i << "\n";
}
