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

  int w, b;
  cin >> w >> b;

  int mw = 1000 * w;
  
  int ans = -1;
  for (int i = 1; i <= 1000000; ++i) {
    if (i * b > mw) ans = i;
    if (ans != -1) break;
  }

  println("{}", ans);
}
