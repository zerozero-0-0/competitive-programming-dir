#include <algorithm>
#include <iostream>
#include <print>
#include <vector>
using namespace std;

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;

  vector<int> B(n, 0), A(n, 0);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (s[i] == 'a') A[0] = 1;
      else B[0] = 1;
    } else {
      A[i] = A[i - 1];
      B[i] = B[i - 1];
      if (s[i] == 'a') A[i]++;
      else B[i]++;
    }
  }
  long long ans = 0;
  for (int l = 0; l < n; l++) {
    if (l == 0) {
      int r1 = lower_bound(B.begin(), B.end(), b) - B.begin();
      r1--; 
      int r2 = lower_bound(A.begin(), A.end(), a) - A.begin();

      if (r2 >= n || r1 < r2) continue;
      ans += (r1 - r2 + 1);

      continue;
    }

    int r1 = lower_bound(B.begin() + l, B.end(), b + B[l - 1]) - B.begin();
    r1--; 
    // B[r1] - B[l - 1] < bを満たす最大のr1

    int r2 = lower_bound(A.begin() + l, A.end(), a + A[l - 1]) - A.begin();
    // A[r2] - A[l - 1] >= aを満たす最小のr2

    if (r2 >= n || r1 < r2) continue;
    ans += (r1 - r2 + 1);
  }

  println("{}", ans);
  return 0;
}
