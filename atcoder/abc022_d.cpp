#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int N;
  cin >> N;

  Polygon p(N), pp(N);
  rep(i, N) cin >> p[i];
  rep(i, N) cin >> pp[i];
  double P = diameter(pp) / diameter(p);
  printf("%.10lf\n", P);

  return 0;
}
