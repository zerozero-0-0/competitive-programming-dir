#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, z;
  cin >> x >> y >> z;

  bool flg = false;
  for (int i = 0; i < 100; i++) {
    if (x == y * z) flg = true;
    x++;
    y++;
  }

  if (flg) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
