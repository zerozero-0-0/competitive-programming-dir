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

  string s;
  cin >> s;
  int n = s.size();

  sort(s.begin(), s.end());

  ll ans = 0;
  do {
    for (int i = 1; i < n; ++i) {
      string a = s.substr(0, i), b = s.substr(i, n);
      if (b.front() == '0' || a.front() == '0') continue;
      ll x = stoll(a), y = stoll(b);
      ll cur = x * y;
      ans = max(ans, cur);
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << ans << "\n";
}
