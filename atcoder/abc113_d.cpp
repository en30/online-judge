#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const ll MOD = 1e9+7;

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
};


int main () {
  using mint = Fp<MOD>;
  int H, W, K;
  cin >> H >> W >> K;

  // t[i][j]: c[i] -> c[j]
  vector<vector<mint>> t(W, vector<mint>(W, 0));

  rep(i,1<<(W-1)) {
    rep(j,W-1) {
      if(((i>>j) & (i>>(j+1)) & 1)) goto next;
    }
    rep(j,W) {
      if(j-1 >= 0 && ((i>>(j-1)) & 1)) {
        t[j][j-1] += 1;
      } else if (j+1 <= W-1 && ((i>>j) & 1)) {
        t[j][j+1] += 1;
      } else {
        t[j][j] += 1;
      }
    }
  next:;
  }

  vector<vector<mint>> c(H+1, vector<mint>(W, 0));
  c[0][0] = 1;
  rep(h,H) {
    rep(i,W) {
      rep(j,W) {
        c[h+1][j] += t[i][j] * c[h][i];
      }
    }
  }

  cout << c[H][K-1] << endl;

  return 0;
}
