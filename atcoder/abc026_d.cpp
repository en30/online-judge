#include <bits/stdc++.h>
#include "../include/template"

int A, B, C;

double g(double t) { return 100 - A * t - B * sin(C * t * M_PI); }

int main() {
  cin >> A >> B >> C;

  double l = 0, r = 1;
  while (g(r) > 0) r *= 10;

  while (true) {
    double m = (l + r) / 2;
    if (g(m) > 0) {
      l = m;
    } else {
      r = m;
    }

    if (abs(g(r) - g(l)) < 1e-8) break;
  }

  printf("%.10lf\n", l);
  return 0;
}
