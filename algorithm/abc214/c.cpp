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

  int n;
  cin >> n;
  vector<ll> s(n),t(n);
  for (auto &i : s) cin >> i;
  for (auto &i : t) cin >> i;

  // vec[2 * n]とすれば、
  // i \in [0 , n) で iからスタートした場合の時刻が得られる
  // その中の最小値を出せばいい
  vector<ll> vec(2 * n);
  rep(i, n) vec[i] = t[i], vec[n + i] = t[i];
  // for (auto i : vec) print("{} ", i);

  // println();
  
  rep(i, 2 * n - 1) {
    if (i < n) vec[i + 1] = min(vec[i + 1], vec[i] + s[i]);
    else vec[i + 1] = min(vec[i + 1], vec[i] + s[i - n]);
  }

  // for (auto i : vec) print("{} ", i);

  rep(i, n) {
    cout << min(vec[i], vec[i + n]) << "\n";
  }
}
