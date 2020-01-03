#include <bits/stdc++.h>
#include "../include/template"

const double EPS = 1e-9;

int txa, tya, txb, tyb, T, V, n;

int main() {
  cin >> txa >> tya >> txb >> tyb >> T >> V;
  cin >> n;

  bool can = false;

  auto dist = [&](int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };

  rep(i, n) {
    int x, y;
    cin >> x >> y;
    can |= (dist(txa, tya, x, y) + dist(txb, tyb, x, y) <= V * T + EPS);
  }

  cout << (can ? "YES" : "NO") << endl;
  return 0;
}
