#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];

  int q;
  cin >> q;
  rep(i, q) {
    Line l;
    cin >> l;
    printf("%.8lf\n", area(convexCut(p, l)));
  }

  return 0;
}
