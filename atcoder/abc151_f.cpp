#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"
#include "../include/ternary_search.hpp"

int N;
vector<Point> P;

double maxDist(double x, double y) {
  Point q(x, y);
  double res = 0;
  rep(i, N) res = max(res, abs(q - P[i]));
  return res;
}

int main() {
  cin >> N;

  P.resize(N);
  rep(i, N) cin >> P[i];

  double ans = minimal(
      [&](double x) {
        return minimal([&](double y) { return maxDist(x, y); }, 0, 1e3);
      },
      0, 1e3);

  printf("%.10lf\n", ans);

  return 0;
}
