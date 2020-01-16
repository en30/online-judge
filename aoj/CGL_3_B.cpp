#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  cout << isConvex(p) << endl;

  return 0;
}
