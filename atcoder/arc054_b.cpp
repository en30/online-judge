#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ternary_search.hpp"

int main() {
  double P;
  cin >> P;

  auto f = [&](double t) { return t + P / pow(2.0, t / 1.5); };

  printf("%.10lf\n", minimal(f, 0, P, 200));

  return 0;
}
