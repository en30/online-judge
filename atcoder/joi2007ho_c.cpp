#include <bits/stdc++.h>
#include "../include/template"

struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const Point& that) const {
    return x == that.x ? y < that.y : x < that.x;
  }
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator-() const { return Point(-x, -y); }
  int norm() const { return x * x + y * y; }
};

int main() {
  int N;
  cin >> N;
  vector<Point> P(N);
  rep(i, N) cin >> P[i].x >> P[i].y;

  sort(all(P));

  int ans = 0;

  auto r1 = [](const Point& p) { return Point(-p.y, p.x); };
  auto r2 = [](const Point& p) { return Point(p.y, -p.x); };
  auto contains = [&](const Point& p) {
    auto r = equal_range(all(P), p);
    return r.first != r.second;
  };

  rep(i, N) rep(j, N) {
    if (i == j) continue;

    auto rel = P[j] - P[i];
    Point p1 = P[i] + r1(rel), p2 = P[j] + r2(-rel);
    if (contains(p1) && contains(p2)) chmax(ans, rel.norm());
    p1 = P[i] + r2(rel), p2 = P[j] + r1(-rel);
    if (contains(p1) && contains(p2)) chmax(ans, rel.norm());
  }

  cout << ans << endl;

  return 0;
}
