#include <bits/stdc++.h>
#include "../include/template"
#include "../include/closest_pair.hpp"

int main() {
  int n;
  cin >> n;
  vector<Point> P(n);
  rep(i, n) cin >> P[i];

  ClosestPair cp(P);
  printf("%.10lf", cp.distance());

  return 0;
}
