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

  ll k;
  cin >> k;

  string ans = "";

  while (k > 0) {
    if (k % 2 == 1) ans.push_back('2');
    else ans.push_back('0');

    k /= 2;
  }

  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
