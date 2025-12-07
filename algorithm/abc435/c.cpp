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

  vector<bool> flg(n);
  int cur = 0;
  rep(i, n) {
    if (i == 0) {
      flg[0] = true;
      cur = i + a[0];
    } else {
      if (i < cur) {
        flg[i] = true;
        cur = max(cur, i + a[i]);
      }
    }
  }

  int ans = 0;
  rep(i, n) if (flg[i]) ++ans;
  println("{}", ans);
}
