#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;
using PQ = priority_queue<ll, vector<ll>, greater<ll>>;

int main() {
  int q;
  cin >> q;

  PQ pq;
  ll sum = 0;

  rep(i, q) {
    int op;
    cin >> op;
    if (op == 1) {
      ll x;
      cin >> x;

      pq.emplace(x - sum);
    } else if (op == 2) {
      ll x;
      cin >> x;
      sum += x;
    } else {
      ll ans = pq.top();
      pq.pop();
      cout << ans + sum << "\n";
    }
  }

  // pqを用いる
  // pqにぶちこむとき x - sum(i - 1)にすれば
  // とりだすときO(1)
}
