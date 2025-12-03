#include <cmath>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  long long n, p;
  cin >> n >> p;

  if (n == 1) {cout << p << endl; return 0;
}
  map<long long, int> mp;

  for (long long i = 2; i * i <= p; i++) {
    while (p % i) {
      p /= i;
      mp[p]++;
    }
  }

  long long ans = 1;
  for (auto [cur, cnt] : mp) {
    if (cnt >= n) {
      int num = cur / n;
      long long a = pow(cur, num);
      ans *= a;
    }
  }

  cout << ans << endl;
}

