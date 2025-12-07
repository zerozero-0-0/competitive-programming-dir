#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

using PQ = priority_queue<int, vector<int>, greater<int>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  vector<int> deg(n);
  
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    deg[b]++;
  }
  
  PQ pq;
  rep(i, n) if (deg[i] == 0) pq.emplace(i);

  vector<int> ans;
  while (pq.size()) {
    int v = pq.top();
    pq.pop();
    ans.push_back(v);
    for (auto u : G[v]) {
      deg[u]--;
      if (deg[u] == 0) pq.push(u);
    }
  }

  if (ans.size() != n) cout << -1 << endl;
  else for (auto i : ans) cout << i + 1 << "\n";
}
