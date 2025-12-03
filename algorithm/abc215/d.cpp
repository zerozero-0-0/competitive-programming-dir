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
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  vector<bool> isPrime(m + 1, false);

  set<int> prime;

  for (auto i : a) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j != 0) continue;
      prime.insert(j);
      while (i % j == 0) {
        i /= j;
      } 
    }
    if (i != 1 && !prime.count(i)) prime.insert(i);
  }

  for (auto i : prime) {
    for (int j = 1; i * j <= m; ++j) {
      isPrime[i * j] = true;
    }
  }

  int cnt = 0;
  vector<int> ans;

  for (int i = 1; i <= m; ++i) {
    if (isPrime[i] == false) {
      ans.push_back(i);
      cnt++;
    }
  }

  cout << cnt << "\n";
  for (auto i : ans) {
    cout << i << "\n";
  }
}
