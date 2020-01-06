#include <bits/stdc++.h>
#include "../include/template"
#include "../include/geometry.hpp"

int N;
vector<Point> P;

int main() {
  Segment chop;
  {
    Point p1, p2;
    cin >> p1 >> p2;
    chop = Segment{p1, p2};
  }

  cin >> N;
  P.resize(N);

  rep(i, N) cin >> P[i];

  vector<Segment> segs(N);
  rep(i, N) segs[i] = Segment{P[i], P[(i + 1) % N]};

  int count = 0;
  rep(i, N) {
    if (intersect(segs[i], chop)) count++;
  }

  cout << 1 + count / 2 << endl;
  return 0;
}
