#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int N;

int main() {
  cin >> N;

  Polygon p(N);
  rep(i, N) cin >> p[i];

  double ans = 1e9;

  auto update = [&](const Circle& c) {
    rep(i, N) if (!c.contains(p[i])) return;
    ans = min(ans, c.r);
  };

  rep(i, N) for (int j = i + 1; j < N; ++j) for (int k = j + 1; k < N; ++k) {
    if (abs(ccw(p[i], p[j], p[k])) != 1) continue;
    Circle c = circumscribedCircle(p[i], p[j], p[k]);
    update(c);
  }

  rep(i, N) for (int j = i + 1; j < N; ++j) {
    Circle c((p[i] + p[j]) / 2.0, abs(p[i] - p[j]) / 2.0);
    update(c);
  }

  printf("%.10lf\n", ans);

  return 0;
}
