#include <bits/stdc++.h>
#include "../include/template"
#include "../include/integer_geometry.hpp"

int main() {
  int m, n;
  cin >> m;
  Point base;
  cin >> base.x >> base.y;
  vector<Point> C(m - 1);
  rep(i, m - 1) {
    cin >> C[i].x >> C[i].y;
    C[i] -= base;
  }

  cin >> n;
  vector<Point> P(n);
  rep(i, n) cin >> P[i].x >> P[i].y;
  vector<Point> sorted(P);
  sort(all(sorted));

  auto contains = [&](const Point& p) { return binary_search(all(sorted), p); };

  auto match = [&](const Point& p) {
    rep(i, m - 1) if (!contains(p + C[i])) return false;
    return true;
  };

  rep(i, n) {
    if (match(P[i])) {
      Point p = P[i] - base;
      cout << p.x << " " << p.y << endl;
      return 0;
    }
  }

  return 0;
}
