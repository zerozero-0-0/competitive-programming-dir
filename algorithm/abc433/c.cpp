#include <algorithm>
#include <iostream>
#include <print>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int>> rle;
  for (int i = 0; i < n;) {
    char c = s[i];
    int cnt = 0;
    while (i < n && c == s[i]) {
      i++;
      cnt++;
    }
    rle.push_back({c, cnt});
  }

  long long ans = 0;
  int m = rle.size();
  for (int i = 0; i < m - 1; i++) {
    if (rle[i].first + 1 != rle[i + 1].first) continue;
    int cur = min(rle[i].second, rle[i + 1].second);
    ans += cur;
  }

  println("{}", ans);
}
