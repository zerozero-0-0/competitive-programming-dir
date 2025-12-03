#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int) n; i++)
using ll = long long;
const int iinf = INT_MAX;
const ll linf = LONG_LONG_MAX;

struct State {
  int a;
  int b;
  int c;
  int d;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n), y(n), r(n);
  rep(i, n) cin >> x[i] >> y[i] >> r[i];

  // 各iがx_i, y_iを含むようにする
  vector<State> ans(n);
  rep(i, n) {
    ans[i].a = x[i];
    ans[i].b = y[i];
    ans[i].c = x[i] + 1;
    ans[i].d = y[i] + 1;
  }

  constexpr int edge = 1e4;
  vector grid(edge, vector<bool> (edge));

  auto expand = [&](int i) {
    int r = rand() % 4;
    // 0, 1, 2, 3 : 左, 上, 右, 下
    if (r == 0) {
     if (ans[i].a - 1 >= 0) ans[i].a--;
    } else if (r == 1) {
      if (ans[i].b - 1 >= 0) ans[i].b--; 
    } else if (r == 2) {
      if (ans[i].c + 1 < edge) ans[i].c++;
    } else if (r == 3) {
      if (ans[i].d + 1 < edge) ans[i].d++;
    }

    for (int i = ans[i].a; i <= ans[i].c; ++i) {
      for (int j = ans[i].b; j <= ans[i].b; ++j) {
        if(grid[i][j])
      } 
    }
  };

  rep(i, n) {
    cout << x[i] << " " << y[i] << " " << x[i] + 1 << " " << y[i] + 1 << "\n";
  }
}
