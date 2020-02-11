#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int main() {
  int N;
  cin >> N;

  vector<Point> P(N);
  rep(i, N) cin >> P[i].x >> P[i].y;

  ll acute = 0, obtuse = 0, right = 0;

  auto rangeCount = [](const vector<double>& v, double l, double r) {
    return distance(lower_bound(all(v), l), lower_bound(all(v), r));
  };

  rep(i, N) {
    vector<double> args;
    rep(j, N) {
      if (i == j) continue;
      args.push_back(arg(P[j] - P[i]));
    }

    sort(all(args));
    int M = args.size();
    rep(i, M) args.push_back(args[i] + 2 * PI);

    rep(i, M) {
      double r1 = args[i] + PI / 2.0, r2 = r1 + PI;
      right += rangeCount(args, r1 - EPS, r1 + EPS);
      obtuse += rangeCount(args, r1 + EPS, r2 - EPS);
      right += rangeCount(args, r2 - EPS, r2 + EPS);
    }
  }

  right /= 2;
  obtuse /= 2;
  acute = (ll(N) * (N - 1) * (N - 2) / 6) - right - obtuse;
  cout << acute << " " << right << " " << obtuse << endl;
  return 0;
}
