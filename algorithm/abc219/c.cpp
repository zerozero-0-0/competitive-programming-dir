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

  string x;
  int n;
  cin >> x >> n;
  vector<string> s(n);
  for (auto &i : s) cin >> i;

  map<char, char> mp;
  char c = 'a';
  for (auto i : x) {
    mp[i] = c;
    ++c;
  }

  vector<pair<string, int>> vec(n);
  rep(i, n) {
    string t = "";
    for (auto j : s[i]) {
      t.push_back(mp[j]);
    }
    vec[i] = {t, i};
  }

  sort(vec.begin(), vec.end());
  for (auto [_, i] : vec) {
    cout << s[i] << "\n";
  }
}
