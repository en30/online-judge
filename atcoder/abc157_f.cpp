#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int N, K;
  cin >> N >> K;
  vector<Point> P(N);
  vector<double> C(N);
  rep(i, N) cin >> P[i] >> C[i];

  auto tooLarge = [&](double t) {
    vector<Point> cand(P);
    vector<Circle> circle(N);
    rep(i, N) circle[i] = Circle(P[i], t / C[i]);
    rep(i, N) {
      rep(j, N) {
        if (i == j || !intersect(circle[i], circle[j])) continue;
        auto p = crossPoint(circle[i], circle[j]);
        cand.push_back(p.first);
        cand.push_back(p.second);
      }
    }
    for (auto &p : cand) {
      int c = 0;
      rep(i, N) if (circle[i].contains(p))++ c;
      if (c >= K) return true;
    }
    return false;
  };

  double l = 0, r = 1e10;
  rep(i, 200) {
    double m = (l + r) / 2;
    if (tooLarge(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  printf("%.7lf\n", l);

  return 0;
}
