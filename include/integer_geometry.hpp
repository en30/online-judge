#pragma once

struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const Point& that) const {
    return x == that.x ? y < that.y : x < that.x;
  }

  Point& operator+=(const Point& p) {
    x += p.x, y += p.y;
    return *this;
  }

  Point& operator-=(const Point& p) {
    x -= p.x, y -= p.y;
    return *this;
  }

  Point& operator*=(int r) {
    x *= r, y *= r;
    return *this;
  }

  Point& operator/=(int r) {
    x /= r, y /= r;
    return *this;
  }

  Point operator+(const Point& p) const { return Point(*this) += p; }
  Point operator-(const Point& p) const { return Point(*this) -= p; }
  Point operator*(int r) const { return Point(*this) *= r; }
  Point operator/(int r) const { return Point(*this) /= r; }
  Point operator-() const { return Point(-x, -y); }
  int norm() const { return x * x + y * y; }
  Point rotate90() const { return Point(-y, x); }
  Point rotate270() const { return Point(y, -x); }
};
