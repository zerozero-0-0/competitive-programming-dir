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

  ll n;
  cin >> n;

  string ans = "";

  while (n > 0) {
    if (n % 2 == 0) {
      n /= 2;
      ans.push_back('B');
    } else {
      n--;
      ans.push_back('A');
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
