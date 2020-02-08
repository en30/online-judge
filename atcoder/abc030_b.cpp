#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, m;
  cin >> n >> m;

  double ans = (360.0 / 12.0) * (n % 12) + (360.0 / 12.0 / 60.0) * m -
               (360.0 / 60.0) * m;
  ans = abs(ans);
  ans = min(ans, 360.0 - ans);
  printf("%.5lf\n", ans);
  return 0;
}
