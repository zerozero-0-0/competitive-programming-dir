#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l, k;
  cin >> n >> l >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  int left = -1, right = 1e9;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    int cnt = 0;
    int prev = 0;
    for (auto i : a) {
      if (i - prev >= mid) {
        cnt++;
        prev = i;
      }
    }

    if (l - prev >= mid) cnt++;

    if (cnt >= k + 1) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << left << endl;
  return 0;
}
