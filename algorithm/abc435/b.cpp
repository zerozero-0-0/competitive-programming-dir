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
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int ans = 0;
  rep(l, n) {
    for(int r = l + 1; r < n; ++r) {
      int cur = 0;
      for (int i = l; i <= r; ++i) cur += a[i];
      bool flg = true;
      for (int i = l; i <= r; ++i) {
        if (cur % a[i] == 0) flg = false;
      }

      if (flg) ++ans;
    }
  }

  println("{}", ans);
}
