#include <bits/stdc++.h>
using namespace std;
#include <atcoder/dsu>
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
constexpr int iinf = INT_MAX;
constexpr long long linf = LONG_LONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  const int nil = -1;
  vector<int> front(n, nil), back(n, nil);

  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      back[x] = y;
      front[y] = x;
    } else if (opt == 2){
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      back[x] = nil;
      front[y] = nil;
    } else {
      int x;
      cin >> x;
      --x;
      while (front[x] != nil) {
        x = front[x];
      }
      vector<int> ans;
      ans.push_back(x);
      int nx = back[x];
      while (nx != nil) {
        ans.push_back(nx);
        nx = back[nx];
      }

      cout << ans.size() << " ";
      for (auto i : ans) cout << i + 1 << " ";
      cout << "\n";
    }
  }
}
