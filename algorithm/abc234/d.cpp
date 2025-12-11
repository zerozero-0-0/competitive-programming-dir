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

  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (auto &i : p) cin >> i;

  set<int> st;
  rep(i, k) st.insert(p[i]);

  cout << *st.begin() << "\n";

  for (int i = k; i < n; ++i) {
    st.insert(p[i]);
    if (st.size() > k) st.erase(st.begin());
    cout << *st.begin() << "\n";
  }
}
