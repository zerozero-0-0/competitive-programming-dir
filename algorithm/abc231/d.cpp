#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  dsu d(n);
  vector<int> deg(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (d.same(a, b)) {
      cout << "No" << "\n";
      return 0;
    }
    d.merge(a, b);
    deg[a]++;
    deg[b]++;
  }

  rep(i, n) {
    if (deg[i] > 2) {
      cout << "No" << "\n";
      return 0;
    }
  }

  cout << "Yes" << "\n";
  return 0;
}
