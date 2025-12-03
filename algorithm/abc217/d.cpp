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

  int l, q;
  cin >> l >> q;

  set<int> st;
  st.insert(0);
  st.insert(l);

  rep(i, q) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      st.insert(x);
    } else {
      auto itr = st.lower_bound(x);
      cout << *itr - *prev(itr) << "\n";
    }
  }
}
