const double EPS = 1e-10;
bool equals(double a, double b) { fabs(a - b) < EPS; }

class Point {
 public:
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
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

struct Segment {
  Point p1, p2;
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
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
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return (p - s.p1).abs();
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return (p - s.p2).abs();
  return distanceLP(s, p);
}

bool intersect(Segment s1, Segment s2);
double distance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min({distanceSP(s1, s2.p1), distanceSP(s1, s2.p2),
              distanceSP(s2, s1.p1), distanceSP(s2, s1.p2)});
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;      // p2, p0, p1
  if (a.norm() < b.norm()) return ONLINE_FRONT;  // p0, p1, p2
  return ON_SEGMENT;                             // p0, p2, p1
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

Point crossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
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
int contains(Polygon g, Point p) {
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

Polygon convexHull(Polygon s) {
  Polygon u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);

  for (int i = 2; i < s.size(); ++i) {
    for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE;
         --n) {
      u.pop_back();
    }
    u.push_back(s[i]);
  }

  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE;
         --n) {
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
