#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int q;
  cin >> q;
  rep(i, q) {
    Segment s1, s2;
    cin >> s1 >> s2;
    printf("%.10lf\n", distance(s1, s2));
  }
  return 0;
}
