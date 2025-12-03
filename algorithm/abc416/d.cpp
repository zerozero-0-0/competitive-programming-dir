#include <algorithm>
#include <deque>
#include <iostream>
#include <print>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n; long long m;
    cin >> n >> m;
    deque<long long> a(n);
    vector<long long> b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      long long l = (b[i] + a.front()) % m, r = (b[i] + a.back()) % m;
      if (l < r) {
        ans += r;
        a.pop_front();
      } else {
        ans += l;
        a.pop_front();
      }
    }
    println("{}", ans);
  }
}
