#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; i++)

using ll = long long;
using ull = unsigned long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;
const ll mod = 998244353;

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

  ll ans = 0;
  // rep(i, n) {
  //   for (int j = i + 1; j < n; j++) {
  //     ll cur = a[i] * digits[j] + a[j];
  //     ans += cur;
  //     ans %= mod;
  //   }
  // }

  // 各整数について足される数は一意に定まる
  // modはどのタイミングでやっても同じ
  // あるiについて
  // \sigma{i + 1 \to n} a[i] * digit[j] + a[j]
  // a[i] * digit[j]を何とかしてO(log n), O(1)にしたい
  // a[j]は累積和でO(1)に抑えられる

  // a[i] * digit[i + 1] + a[i] * digit[i + 2] + ... a[i] * digit[n]
  // a[i] * (digit[i + 1] + digit[i + 2] + ... + digit[n])
  
  vector<ll> digit_sum(n);
  digit_sum[0] = digits[0];
  rep(i, n - 1) {
    digit_sum[i + 1] = digits[i + 1] + digit_sum[i];
  } 

  vector<ll> sum(n);
  sum[0] = a[0];
  rep(i, n - 1) {
    sum[i + 1] = sum[i] + a[i + 1];
  }

  rep(i, n) {
    ll dds = digit_sum[n - 1] - digit_sum[i];
    ll ds = sum[n - 1] - sum[i];
    dds %= mod;
    ds %= mod;
    ll adds = a[i] * dds;
    ll cur = adds + ds;
    ans += cur;
    ans %= mod;
  }

  cout << ans << "\n";
}
