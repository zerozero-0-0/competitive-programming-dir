#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;
  vector a(h, vector<long long> (w));
  for (auto &i : a) {
    for (auto &j : i) cin >> j;
  }

  vector isCovered(h, vector<bool> (w));

  long long ans = 0;
  auto solve = [&](auto solve, vector<vector<bool>> isCoverd, int i, int j) {
    
  }
}
