#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k;
  cin >> s >> k;
  const int n = s.size();

  int r = 0;
  int ans = 0;
  int cnt = 0; 
  rep(l, n) {
    while (r < n && (s[r] == 'X' || cnt < k)) {
      if (s[r] == '.') ++cnt;
      ++r;
    }
    
    ans = max(ans, r - l);
    
    if (s[l] == '.') --cnt;
  }

  cout << ans << "\n";
}
