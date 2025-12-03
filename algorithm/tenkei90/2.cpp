#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  set<string> st;
  auto solve = [&](auto solve, string s) -> void {
    if (s.size() == n) {
      st.insert(s);
    } else {
      string a = s;
      string b = s;
      a.push_back('(');
      b.push_back(')');
      solve(solve, a);
      solve(solve, b);
    }
  };

  solve(solve, "");
  for (auto s : st) {
    bool flg = true;
    int u = 0;
    for (char c : s) {
      if (c == '(') u++;
      else u--;
      if (u < 0) flg = false;
    }
    if (u != 0 || !flg) continue;
    cout << s << "\n";
  }
  return 0;
}
