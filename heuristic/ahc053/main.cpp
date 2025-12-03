#include <bits/stdc++.h>
using namespace std;

int main() {
  const int n = 500, m = 50;
  long long l = 1e15 - 2 * 1e12, u = 1e15 + 2 * 1e12;

  int _;
  for (int i = 0; i < 4; i++) {
    cin >> _;
  }

  vector<long long> a(n);
  set<long long> alreadyAssingedIntger;
  for (int i = 0; i < n; i++) {
    long long r = rand() % (u - l + 1) + l;
    if (alreadyAssingedIntger.count(r)) {
      i--;
      continue;
    }
    a[i] = r;
    alreadyAssingedIntger.insert(r);
  }

  sort(a.begin(), a.end());

  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;

  vector<long long> b(m);
  for (auto &i : b) cin >> i;


}
