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
  int k;
  cin >> s >> k;

  vector<string> ans;
  sort(s.begin(), s.end());

  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans[k - 1] << "\n";
}
