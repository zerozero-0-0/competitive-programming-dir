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

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  while (q--) {
    int x;
    cin >> x;
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();

    if (idx == n) cout << 0 << "\n";
    else {
      cout << n - idx << "\n";
    }
  }
}
