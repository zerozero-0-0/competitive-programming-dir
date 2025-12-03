#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
using mint = modint998244353;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) cin >> i;

  vector<ll> digits(n);
  rep(i, n) {
    ll cur = to_string(a[i]).size();
    ll digit = 1;
    while (cur--) {
      digit *= 10;
    }
    digits[i] = digit;
  }

  // 各整数について足される数は一意に定まる
  // modはどのタイミングでやっても同じ
  // あるiについて
  // \sigma{i + 1 \to n} a[i] * digit[j] + a[j]
  // a[i] * digit[j]を何とかしてO(log n), O(1)にしたい
  // a[j]は累積和でO(1)に抑えられる

  // a[i] * digit[i + 1] + a[i] * digit[i + 2] + ... a[i] * digit[n]
  // a[i] * (digit[i + 1] + digit[i + 2] + ... + digit[n])
  
  vector<mint> digit_sum(n);
  digit_sum[0] = digits[0];
  rep(i, n - 1) {
    digit_sum[i + 1] = digits[i + 1] + digit_sum[i];
  } 

  vector<mint> sum(n);
  sum[0] = a[0];
  rep(i, n - 1) {
    sum[i + 1] = sum[i] + a[i + 1];
  }

  mint ans = 0;
  rep(i, n) {
    mint dds = digit_sum[n - 1] - digit_sum[i];
    mint ds = sum[n - 1] - sum[i];
    mint adds = a[i] * dds;
    mint cur = adds + ds;
    ans += cur;
  }

  cout << ans.val() << "\n";
}
