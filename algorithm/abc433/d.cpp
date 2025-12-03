#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  vector<vector<int>> as(11);
  for (int i = 0; i < n; i++) {
    as[to_string(a[i]).size()].push_back(a[i]);
  }

  long long ans = 0;
  long long ten = 1;
  for (int b = 0; b < 11; b++) {
    unordered_map<int, int> mp;
    for (int na : as[b]) mp[na % m]++;
    for (int i = 0; i < n; i++) {
      long long r = (-ten * a[i] % m + m) % m;
      ans += mp[r];
    }
    ten *= 10; ten %= m;
  }

  cout << ans << "\n";
  return 0;
}
