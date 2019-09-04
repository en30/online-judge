#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N;

struct V {
  ll x, y;

  V(ll x = 0, ll y = 0): x(x), y(y) {};

  ll r2() const {
    return dot(*this);
  }

  V& operator += (const V &v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  ll cross(const V& that) const {
    return x * that.y - that.x * y;
  }

  ll dot(const V& that) const {
    return x * that.x + y * that.y;
  }

  int orthant() const {
    if(x == 0 && y == 0) return 0;
    if(x > 0 && y >= 0) return 1;
    if(x <= 0 && y > 0) return 2;
    if(x < 0 && y <= 0) return 3;
    return 4;
  }

  bool operator < (const V &that) const {
    int o1 = orthant(), o2 = that.orthant();
    if(o1 != o2) return o1 < o2;
    return cross(that) > 0;
  }
};

vector<V> x;

int main () {
  cin >> N;

  rep(i,N) {
    ll a, b;
    cin >> a >> b;
    x.emplace_back(a, b);
  }

  sort(all(x));

  ll ans = 0;
  rep(i,N) {
    V c(0, 0);
    rep(j,N) {
      c += x[(i+j)%N];
      ans = max(ans, c.r2());
    }
  }

  cout << fixed << setprecision(12) << sqrt(ans) << endl;

  return 0;
}
