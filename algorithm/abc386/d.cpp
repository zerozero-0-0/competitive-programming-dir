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

  int n, m;
  cin >> n >> m;
  map<int, set<pair<int, char>>> mx, my;
  set<int> sx, sy;
  while (m--) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    mx[x].insert({y, c});
    my[y].insert({x, c});
    sx.insert(x);
    sy.insert(y);
  }

  bool flg = true;
  int b = n;
  for (auto cs : sx) {
    int w_pos = 1e9;
    bool w_exist = false;
    for (auto [cy, c] : mx[cs]) {
      if (c == 'B' && w_exist) flg = false;
      if (c == 'W') w_exist = true, w_pos = min(w_pos, cy);
      if (c == 'W' && cy > b) flg = false;
    }

    if (w_exist) b = min(b, w_pos);
  }

  int w = n;
  for (auto cs : sy) {
    int b_pos = 1e9;
    bool b_exist = false;
    for (auto [cx, c] : my[cs]) {
      if ()
    }
  }

  if (flg) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
