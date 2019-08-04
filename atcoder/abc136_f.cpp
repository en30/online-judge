#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

struct Point {
  int x, y;
};

int N;
vector<Point> P;

const ll MOD = 998244353;

template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) v += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
    return is >> x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
  friend constexpr Fp<MOD> modinv(const Fp<MOD> &a) noexcept {
    return modpow(a, MOD - 2);
  }
};

using mint = Fp<MOD>;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1) {}
  void add(int i, T x = 1) {
    for(i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }

  T sum(int i) {
    T x = 0;
    for(i++; i ; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
};

int main () {
  cin >> N;
  P.resize(N);

  rep(i,N) {
    cin >> P[i].x >> P[i].y;
  }

  {
    map<int, int> m;
    rep(i,N) m[P[i].x] = 0;
    int i = 0;
    for(auto && x: m) x.second = i++;
    rep(i,N) P[i].x = m[P[i].x];
  }
  {
    map<int, int> m;
    rep(i,N) m[P[i].y] = 0;
    int i = 0;
    for(auto && x: m) x.second = i++;
    rep(i,N) P[i].y = m[P[i].y];
  }

  mint ans = 0;
  mint two = 2;
  vector<vector<ll>> c(N, vector<ll>(4));
  sort(all(P), [&](const Point &a, const Point &b) {
      return a.x < b.x;
    });

  {
    BIT<int> bit(N);
    rep(i,N) {
      c[i][2] = bit.sum(P[i].y);
      c[i][1] = i - c[i][2];
      bit.add(P[i].y);
    }
  }
  {
    BIT<int> bit(N);
    for(int i = N - 1; i >= 0; i--) {
      c[i][3] = bit.sum(P[i].y);
      c[i][0] = N - 1 - i - c[i][3];
      bit.add(P[i].y);
    }
  }

  vector<mint> o(4), ox(4);
  rep(i,N) {
    rep(j,4) {
      ox[j] = modpow(two, c[i][j]);
      o[j] = ox[j] - 1;
    }
    ans += ox[0] * ox[1] * ox[2] * ox[3];
    ans += o[0] * ox[1] * o[2] * ox[3];
    ans += ox[0] * o[1] * ox[2] * o[3];
    ans -= o[0] * o[1] * o[2] * o[3];
  }

  cout << ans << endl;

  return 0;
}
