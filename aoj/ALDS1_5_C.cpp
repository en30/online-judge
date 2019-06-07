#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class Point {
public:
  double x, y;

  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }

  Point rotate(double rad) {
    double s = sin(rad);
    double c = cos(rad);
    return Point(c*x - s*y, s*x + c*y);
  }
};

Point operator * (const Point& p, double r) {
  return Point(p.x*r, p.y*r);
}

Point operator * (double r, const Point& p) {
  return p*r;
}

Point operator / (const Point& p, double r) {
  return Point(p.x/r, p.y/r);
}

Point operator + (const Point& p1, const Point& p2) {
  return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator - (const Point& p1, const Point &p2) {
  return Point(p1.x - p2.x, p1.y - p2.y);
}

const double PI = 4.0 * atan(1.0);
auto rotate60 = bind(&Point::rotate, placeholders::_1, PI / 3.0);

void koch(int n, Point p1, Point p2) {
  if(n == 0) {
    printf("%lf %lf\n", p2.x, p2.y);
    return;
  }

  Point p12 = p2 - p1;
  Point su = rotate60(p12/3.0);
  Point s = p1 + p12 / 3.0;
  Point u = s + su;
  Point t = p1 + p12 * 2.0 / 3.0;

  koch(n-1, p1, s);
  koch(n-1, s, u);
  koch(n-1, u, t);
  koch(n-1, t, p2);
}

int main () {
  int n;
  cin >> n;
  printf("%lf %lf\n", 0.0, 0.0);
  koch(n, Point(0.0, 0.0), Point(100.0, 0.0));
  return 0;
}
