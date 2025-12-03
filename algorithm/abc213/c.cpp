#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  int h_sum = 0, w_sum = 0;
  map<int, int> mi, mj;
  set<int> si, sj;
  for (auto i : a) si.insert(i);
  for (auto j : b) sj.insert(j);

  int cnt = 1;
  for (auto i : si) {
    mi[i] = cnt;
    cnt++;
  }

  cnt = 1;
  for (auto j : sj) {
    mj[j] = cnt;
    cnt++;
  }

  rep(i, n) {
    cout << mi[a[i]] << " " << mj[b[i]] << "\n";
  }
}
