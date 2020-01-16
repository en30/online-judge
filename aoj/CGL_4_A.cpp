#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];

  auto ch = convexHull(p, true);

  int m = ch.size();

  int k = 0;
  rep(i, m) {
    if (equals(ch[i].y, ch[k].y) ? ch[i].x < ch[k].x : ch[i].y < ch[k].y) k = i;
  }

  cout << m << endl;
  rep(i, m) cout << ch[(i + k) % m].x << " " << ch[(i + k) % m].y << endl;

  return 0;
}
