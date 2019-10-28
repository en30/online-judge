#include <bits/stdc++.h>
#include "../include/template"

int a, b, x;

int main() {
  cin >> a >> b >> x;

  double l = 0, r = M_PI / 2.0 - 1e-7;

  while (r - l > 1e-8) {
    double m = (l + r) / 2;
    double v;
    if (a * tan(m) > b) {
      v = a * b * b / tan(m) * 0.5;
    } else {
      v = a * a * b - a * a * a * tan(m) * 0.5;
    }

    if (v >= double(x)) {
      l = m;
    } else {
      r = m;
    }
  }

  double ans = l / M_PI * 180.0;
  cout << setprecision(7) << ans << endl;
  return 0;
}
