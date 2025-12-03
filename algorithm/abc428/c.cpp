#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int q;
  cin >> q;

  vector<int> vec;
  vec.emplace_back(0);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      char c;
      cin >> c;

      int nx = vec.back() + (c == '(' ? 1 : -1);
      if (nx < 0) {
        nx = -1e9;
      }

      vec.push_back(nx);
    } else {
      vec.pop_back();
    }

    if (vec.back() == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
