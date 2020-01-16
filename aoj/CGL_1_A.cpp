#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  Segment s;
  cin >> s.p1 >> s.p2;

  int q;
  cin >> q;
  rep(i, q) {
    Point p, q;
    cin >> p;
    q = project(s, p);
    printf("%.10lf %.10lf\n", q.x, q.y);
  }

  return 0;
}
