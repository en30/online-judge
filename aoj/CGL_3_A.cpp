#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  printf("%.1lf\n", area(p));

  return 0;
}
