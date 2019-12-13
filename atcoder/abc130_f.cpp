#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> x, y;
vector<char> d;

int main() {
  cin >> N;
  x.resize(N), y.resize(N), d.resize(N);

  rep(i, N) cin >> x[i] >> y[i] >> d[i];

  map<char, double> xMax, xMin, yMax, yMin;
  const vector<char> dirs = {'U', 'D', 'R', 'L'};
  for (auto dir : dirs) {
    xMax[dir] = -1e10;
    xMin[dir] = 1e10;
    yMax[dir] = -1e10;
    yMin[dir] = 1e10;
  }

  rep(i, N) {
    xMax[d[i]] = max(xMax[d[i]], (double)x[i]);
    xMin[d[i]] = min(xMin[d[i]], (double)x[i]);
    yMax[d[i]] = max(yMax[d[i]], (double)y[i]);
    yMin[d[i]] = min(yMin[d[i]], (double)y[i]);
  }

  function<double(double)> dx = [&](double t) {
    return max({xMax['R'] + t, xMax['L'] - t, xMax['U'], xMax['D']}) -
           min({xMin['R'] + t, xMin['L'] - t, xMin['U'], xMin['D']});
  };
  function<double(double)> dy = [&](double t) {
    return max({yMax['U'] + t, yMax['D'] - t, yMax['L'], yMax['R']}) -
           min({yMin['U'] + t, yMin['D'] - t, yMin['L'], yMin['R']});
  };

  auto s = [&](double t) { return dx(t) * dy(t); };

  vector<double> T;
  vector<vector<double>> rs({
      {xMax['R'], xMax['L'], max(xMax['U'], xMax['D'])},
      {xMin['R'], xMin['L'], min(xMin['U'], xMin['D'])},
      {yMax['U'], yMax['D'], max(yMax['R'], yMax['L'])},
      {yMin['U'], yMin['D'], min(yMin['R'], yMin['L'])},
  });

  T.push_back(0);
  for (auto r : rs) rep(i, 3) rep(j, 3) {
      double t = r[i] - r[j];
      if (i == j || t < 0) continue;
      if (i != 2 && j != 2) t /= 2;
      T.push_back(t);
    };

  // auto search = [&](function<bool(double)> f) {
  //   double l = 0.0, r = 1e10;
  //   while (r - l > eps) {
  //     double m = (l + r) / 2;
  //     if (f(m)) {
  //       l = m;
  //     } else {
  //       r = m;
  //     }
  //   }
  //   return l;
  // };
  // T.push_back(search([&](double m) { return dx(m + eps / 2) - dx(m) < 0; }));
  // T.push_back(
  //     search([&](double m) { return dx(m + eps / 2) - dx(m) < eps / 2; }));
  // T.push_back(search([&](double m) { return dy(m + eps / 2) - dy(m) < 0; }));
  // T.push_back(
  //     search([&](double m) { return dy(m + eps / 2) - dy(m) < eps / 2; }));

  double ans = 1e17;
  for (double t : T) ans = min(ans, s(t));

  printf("%.10lf\n", ans);

  return 0;
}
