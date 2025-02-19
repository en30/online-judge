const double EPS = 1e-10;
const double PI = acos(-1);
bool equals(double a, double b) { return fabs(a - b) < EPS; }

class Point {
  double add(double a, double b) const {
    if (fabs(a + b) < EPS * (fabs(a) + fabs(b))) return 0;
    return a + b;
  }

 public:
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(const Point &p) const {
    return Point(add(x, p.x), add(y, p.y));
  }
  Point operator-(const Point &p) const {
    return Point(add(x, -p.x), add(y, -p.y));
  }
  Point operator*(const double a) { return Point(a * x, a * y); }
  Point operator/(const double a) { return Point(x / a, y / a); }

  double abs() const { return sqrt(norm()); }
  double norm() const { return x * x + y * y; }

  Point rotate(double theta) const {
    return Point(cos(theta) * x - sin(theta) * y,
                 sin(theta) * x + cos(theta) * y);
  }

  Point normalize() const { return Point(*this) / abs(); }

  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }

  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }

  friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
};

double abs(const Point &p) { return p.abs(); }
double norm(const Point &p) { return p.norm(); }

typedef Point Vector;

class Segment {
 public:
  Point p1, p2;
  Segment() {}
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
  friend istream &operator>>(istream &is, Segment &s) {
    return is >> s.p1 >> s.p2;
  }
};

typedef Segment Line;

class Circle {
 public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}

  int contains(const Point &p) const {
    double d = abs(c - p);
    if (equals(d, r)) return 1;  // ON
    if (d < r + EPS) return 2;   // IN
    return 0;                    // OUT
  }
};

typedef vector<Point> Polygon;

double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2) {
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }

bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
}

Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }

double distance(Point a, Point b) { return (a - b).abs(); }

double distanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

double distanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < -EPS) return (p - s.p1).abs();
  if (dot(s.p1 - s.p2, p - s.p2) < -EPS) return (p - s.p2).abs();
  return distanceLP(s, p);
}

bool intersect(Segment s1, Segment s2);
double distance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min({distanceSP(s1, s2.p1), distanceSP(s1, s2.p2),
              distanceSP(s2, s1.p1), distanceSP(s2, s1.p2)});
}

enum CCW {
  COUNTER_CLOCKWISE = 1,
  CLOCKWISE = -1,
  ONLINE_BACK = 2,
  ONLINE_FRONT = -2,
  ON_SEGMENT = 0,
};

CCW ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;      // p2, p0, p1
  if (a.norm() < b.norm()) return ONLINE_FRONT;  // p0, p1, p2
  return ON_SEGMENT;                             // p0, p2, p1
}

bool onLine(Line l, Point p) {
  int c = ccw(l.p1, l.p2, p);
  return c != CLOCKWISE && c != COUNTER_CLOCKWISE;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point crossPoint(Line s1, Line s2) {
  assert(!isParallel(s1, s2));
  Vector base = s2.p2 - s2.p1;
  double d1 = cross(base, s2.p1 - s1.p1);
  double d2 = cross(base, s1.p2 - s1.p1);
  double t = d1 / d2;
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

bool intersect(Circle c, Line l) { return distanceLP(l, c.c) < c.r; }

pair<Point, Point> crossPoint(Circle c, Line l) {
  assert(intersect(c, l));
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
  double base = sqrt(c.r * c.r - norm(pr - c.c));
  return make_pair(pr + e * base, pr - e * base);
}

double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

bool intersect(Circle c1, Circle c2) {
  return (c1.c - c2.c).abs() < c1.r + c2.r;
}

pair<Point, Point> crossPoint(Circle c1, Circle c2) {
  assert(intersect(c1, c2));
  double d = abs(c1.c - c2.c);
  double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  double t = arg(c2.c - c1.c);
  return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

/*
  IN 2
  ON 1
  OUT 0
*/
int contains(const Polygon &g, Point p) {
  int n = g.size();
  bool x = false;
  for (int i = 0; i < n; ++i) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS & EPS < b.y && cross(a, b) > EPS) x = !x;
  }
  return (x ? 2 : 0);
}

Polygon convexHull(Polygon s, bool includeOnSegment = false) {
  Polygon u, l;

  if (s.size() < 3) return s;
  sort(s.begin(), s.end());

  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);

  auto bad = [&](Point p1, Point p2, Point p3) {
    if (includeOnSegment) {
      return ccw(p1, p2, p3) == COUNTER_CLOCKWISE;
    } else {
      return ccw(p1, p2, p3) != CLOCKWISE;
    }
  };

  for (int i = 2; i < s.size(); ++i) {
    for (int n = u.size(); n >= 2 && bad(u[n - 2], u[n - 1], s[i]); --n) {
      u.pop_back();
    }
    u.push_back(s[i]);
  }

  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && bad(l[n - 2], l[n - 1], s[i]); --n) {
      l.pop_back();
    }
    l.push_back(s[i]);
  }

  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; --i) l.push_back(u[i]);

  return l;
}

Circle circumscribedCircle(const Point &a, const Point &b, const Point &c) {
  double a1, a2, b1, b2, c1, c2;
  a1 = 2 * (b.x - a.x);
  b1 = 2 * (b.y - a.y);
  c1 = a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
  a2 = 2 * (c.x - a.x);
  b2 = 2 * (c.y - a.y);
  c2 = a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
  Point p;
  p.x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
  p.y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);

  return Circle(p, abs(p - a));
}

// https://en.wikipedia.org/wiki/Green's_theorem#Area_Calculation
double area(const Polygon &p) {
  double ans = 0;
  const int N = p.size();
  for (int i = 0; i < N; ++i) {
    Point q = p[(i + 1) % N];
    ans += (p[i].y + q.y) * (q.x - p[i].x);
  }
  ans /= 2.0;
  return fabs(ans);
}

// The points must be counter-clockwise order
bool isConvex(const Polygon &p) {
  const int N = p.size();

  for (int i = 0; i < N; ++i) {
    Point pn = p[(i + 1) % N], pnn = p[(i + 2) % N];
    int d = ccw(p[i], pn, pnn);
    if (d == CLOCKWISE) return false;
  }
  return true;
}

// Rotating calipers or Shamos's algorithm
pair<Point, Point> farthestPoints(const Polygon &p) {
  Polygon ch = convexHull(p);

  int n = ch.size();
  if (n == 2) return make_pair(ch[0], ch[1]);
  int i = 0, j = 0;
  for (int k = 0; k < n; ++k) {
    if (!(ch[i] < ch[k])) i = k;
    if (ch[j] < ch[k]) j = k;
  }

  pair<Point, Point> res;
  double d = 0;
  int si = i, sj = j;
  while (i != sj || j != si) {
    double cd = abs(ch[i] - ch[j]);
    if (cd > d) {
      d = cd;
      res = make_pair(ch[i], ch[j]);
    }

    if (cross(ch[(i + 1) % n] - ch[i], ch[(j + 1) % n] - ch[j]) < 0) {
      i = (i + 1) % n;
    } else {
      j = (j + 1) % n;
    }
  }
  return res;
}

double diameter(const Polygon &p) {
  pair<Point, Point> pts = farthestPoints(p);
  return abs(pts.first - pts.second);
}

Polygon convexCut(const Polygon &p, const Line &l) {
  const int n = p.size();
  Polygon res;

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    Segment s = Segment(p[i], p[j]);

    if (isParallel(s, l)) continue;
    Point q = crossPoint(s, l);
    if (ccw(p[i], p[j], q) != ON_SEGMENT) continue;
    if (cross(l.p2 - l.p1, s.p2 - s.p1) < EPS) continue;
    res.push_back(q);

    for (;; j = (j + 1) % n) {
      res.push_back(p[j]);
      Segment s = Segment(p[j], p[(j + 1) % n]);
      if (isParallel(s, l)) continue;

      Point q = crossPoint(Segment(p[j], p[(j + 1) % n]), l);
      if (ccw(p[j], p[(j + 1) % n], q) != ON_SEGMENT) continue;
      if (cross(l.p2 - l.p1, s.p2 - s.p1) > -EPS) continue;
      res.push_back(q);
      return res;
    }
  }

  // no intersection
  if (ccw(l.p1, l.p2, p[0]) == COUNTER_CLOCKWISE) return p;
  return res;
}
