#pragma once
#include "./geometry.hpp"

class ClosestPair {
  struct Pair {
    Point p1, p2;
    double d;
    Pair(const Point &p1, const Point &p2) : p1(p1), p2(p2), d(abs(p1 - p2)){};
    bool operator<(const Pair &that) const { return d < that.d; }
  };

  vector<Point> P;
  Pair INF = Pair(Point(-INFINITY, -INFINITY), Point(INFINITY, INFINITY));
  Pair result;

  static bool lessY(const Point &a, const Point &b) { return a.y < b.y; };

  // [l, r)
  Pair divideAndConquer(int l, int r) {
    if (r - l <= 1) return INF;

    int m = (l + r) / 2;
    double x = P[m].x;
    Pair res = min(divideAndConquer(l, m), divideAndConquer(m, r));
    auto it = P.begin();
    inplace_merge(it + l, it + m, it + r, lessY);

    vector<Point> b;
    for (int i = l; i < r; ++i) {
      if (fabs(P[i].x - x) >= res.d) continue;

      for (int j = int(b.size()) - 1; j >= 0; --j) {
        if (P[i].y - b[j].y >= res.d) break;
        res = min(res, Pair(P[i], b[j]));
      }
      b.push_back(P[i]);
    }
    return res;
  };

 public:
  /**
   * @brief 最近接点 O(N log N)
   * @param _P
   */
  ClosestPair(const vector<Point> &_P) : P(_P), result(INF) {
    sort(P.begin(), P.end(),
         [](const Point &a, const Point &b) { return a.x < b.x; });

    result = divideAndConquer(0, P.size());
  }

  double distance() { return result.d; }

  pair<Point, Point> points() { return make_pair(result.p1, result.p2); }
};
