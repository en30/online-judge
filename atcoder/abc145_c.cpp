#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<double> x, y;

int main() {
  cin >> N;
  x.resize(N), y.resize(N);

  rep(i, N) cin >> x[i] >> y[i];

  double ans = 0;
  rep(i, N) rep(j, N) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    ans += sqrt(dx * dx + dy * dy);
  }
  ans /= N;

  printf("%.8lf\n", ans);
  return 0;
}
