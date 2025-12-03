#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
const int imod = INT_MAX;
const long long lmod = LONG_LONG_MAX;

int main() {
  int n, c;
  ll m;
  cin >> n >> m >> c;
  vector<ll> a(n);
  map<ll, int> mp;
  for (auto &i : a) {
    cin >> i;
    mp[i]++;
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  // O(N)なら間に合うのでA[i]が何回数えられるかを考えれば行けそう
  rep(i, n) {
    int prev = (i == 0) ? a.back() : a[i - 1];
    
  }  
}
