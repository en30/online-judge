#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

struct Point {
  int x, y;
};

Point operator+(const Point& p1, const Point& p2) {
  return Point{p1.x+p2.x, p1.y+p2.y};
}
Point operator-(const Point& p1, const Point& p2) {
  return Point{p1.x-p2.x, p1.y-p2.y};
}

Point rotate(Point v) {
  return Point{-v.y, v.x};
}

int main () {
  Point v1, v2;
  cin >> v1.x >> v1.y >> v2.x >> v2.y;

  Point v3 = v2 + rotate(v2 - v1);
  Point v4 = v3 + rotate(v3 - v2);

  printf("%d %d %d %d\n", v3.x, v3.y, v4.x, v4.y);

  return 0;
}
