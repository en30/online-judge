#include <bits/stdc++.h>
#include "../include/template"

double a, b, x;

int main() {
  cin >> a >> b >> x;

  double s = x / a;
  double rad;
  if (s >= a * b / 2) {
    rad = atan2((b - s / a) * 2, a);
  } else {
    rad = atan2(b, 2 * s / b);
  }
  double PI = acos(-1);
  double ans = rad / PI * 180.0;

  cout << setprecision(7) << ans << endl;
  return 0;
}
