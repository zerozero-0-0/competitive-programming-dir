#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> a(2 * n);
  for (auto &i : a) cin >> i;

  vector<pair<int, int>> rank(2 * n);
  rep(i, 2 * n) rank[i] = {0, i};

  auto janken = [&](char a, char b) {
    if (a == 'G' && b == 'C') return true;
    if (a == 'P' && b == 'G') return true;
    if (a == 'C' && b == 'P') return true;
    return false;
  };

  rep(round, m) {
    rep(i, n) {
      int p1 = 2 * i, p2 = 2 * i + 1;
      int cr1 = rank[p1].second, cr2 = rank[p2].second;
      bool result = janken(a[cr1][round], a[cr2][round]);

      if (janken(a[cr1][round], a[cr2][round])) rank[p1].first--;
      if (janken(a[cr2][round], a[cr1][round])) rank[p2].first--;

    }

    sort(rank.begin(), rank.end());
  }

  rep(i, 2 * n) cout << rank[i].second + 1 << "\n";
}
