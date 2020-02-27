#include <bits/stdc++.h>
#include "../include/template"
#include "../include/integer_geometry.hpp"

int main() {
  int N;
  cin >> N;
  vector<Point> P(N);
  rep(i, N) cin >> P[i].x >> P[i].y;

  sort(all(P));

  int ans = 0;

  auto contains = [&](const Point& p) { return binary_search(all(P), p); };

  rep(i, N) rep(j, N) {
    if (i == j) continue;

    auto rel = P[j] - P[i];
    Point p1 = P[i] + rel.rotate90(), p2 = P[j] - rel.rotate270();
    if (contains(p1) && contains(p2)) chmax(ans, rel.norm());
    p1 = P[i] + rel.rotate270(), p2 = P[j] - rel.rotate90();
    if (contains(p1) && contains(p2)) chmax(ans, rel.norm());
  }

  cout << ans << endl;

  return 0;
}
