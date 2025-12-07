#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll n = pow(2, 20);

  int q;
  cin >> q;

  map<ll, int> mp;
  set<int> undefined;

  while (q--) {
    int t;
    ll x;
    cin >> t >> x;

    if (t == 1) {
      ll h = x;
      while (st.count(h % n)) {
        ++h;
      }
      // ここがやばいから高速化したい
      // xから右を見て1番近い未定義の場所を知りたい

      mp[h % n] = x;
      st.insert(h % n);
    } else {
      if (st.count(x % n)) cout << mp[x % n] << "\n";
      else cout << -1 << "\n";
    }
  }
}
