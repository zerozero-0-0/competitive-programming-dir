#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  for (int i = 0; i < n; i++) {
    int ans = -2;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        ans = j;
      }
    }


    cout << ans + 1 << "\n";
  }
}
