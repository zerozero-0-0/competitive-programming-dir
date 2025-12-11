#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, a, b;
  cin >> n >> a >> b;
  ll p, q, r, s;
  cin >> p >> q >> r >> s;

  const ll h = q - p + 1, w = s - r + 1;

  vector<string> grid(h, string(w, '.'));

  rep(i, h) {
    rep(j, w) {
      ll x = p + 1, y = r + j;
      if (x - y)
    }
  }
}
