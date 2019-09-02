#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

struct V {
  double x, y, t;

  V(double x = 0, double y = 0): x(x), y(y), t(atan2(y,x)) {
  };

  bool operator < (const V &that) {
    return t < that.t;
  }

  V& operator += (const V &v) {
    x += v.x;
    y += v.y;
    return *this;
  }
};

vector<V> x;

int main () {
  cin >> N;

  rep(i,N) {
    double a, b;
    cin >> a >> b;
    x.emplace_back(a, b);
  }

  sort(all(x));

  double ans = 0;
  rep(i,N) {
    V c(0, 0);
    rep(j,N) {
      c += x[(i+j)%N];
      ans = max(ans, c.x*c.x + c.y*c.y);
    }
  }

  cout << fixed << setprecision(12) << sqrt(ans) << endl;

  return 0;
}
