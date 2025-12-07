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
  vector b(n, vector<int> (m));
  rep(i, n) rep(j, m) cin >> b[i][j];

  auto f = [&] () {
    rep(i, n) {
      rep(j, m) {
        if (j < m - 1) {
          if (b[i][j + 1] != b[i][j] + 1) return false;
        }

        if (i < n - 1 && b[i + 1][j] != b[i][j] + 7) return false;
      }
      if (i < n - 1) {
        int d = b[i + 1][0] - b[i][m - 1];
        if (d - 1 + m != 7) return false;
      }
    }
    return true;
  };

  if (f()) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
