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
  vector<vector<bool>> G(n, vector<bool> (n));
  vector<vector<bool>> H(n, vector<bool> (n));

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a][b] = true;
    G[b][a] = true;
  }

  rep(i, m) {
    int c, d;
    cin >> c >> d;
    --c;
    --d;
    H[c][d] = true;
    H[d][c] = true;
  }

  vector<int> num(n);
  iota(num.begin(), num.end(), 0);

  bool flg = false;

  do {
    bool ok = true;
    rep(i, n) {
      rep(j, n) {
        if (G[i][j] != H[num[i]][num[j]]) ok = false;
      }
    }

    flg |= ok;
  } while (next_permutation(num.begin(), num.end()));

  if (flg) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
