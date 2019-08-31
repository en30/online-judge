#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()


ll L, R;

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
  friend constexpr Fp<MOD> modinv(const Fp<MOD> &a) noexcept {
    return modpow(a, MOD - 2);
  }
};

using mint = Fp<MOD>;

const int D = 64;

vector<mint> fact(D, 1), ifact(D, 1);

mint comb(int n, int k) {
  return fact[n] * ifact[n-k] * ifact[k];
}

mint f(ll x) {
  vector<mint> c(D, 0);
  int m = D - 1;
  while(m >= 0 && (((x >> m) & 1) == 0)) m--;
  for(int i = 0; i < m - 1; i++) {
    for(int j = 0; j <= i; j++) {
      c[j] += comb(i, j);
    }
  }

  int k = 0;
  while(m >= 0) {
    m--;
    while(m >= 0 && (((x >> m) & 1) == 0)) {
      k++;
      m--;
    }
    for(int i = 0; i < m; i++) {
      c[i+k+1] += comb(m, i);
    }
  }

  mint ans = 0;
  rep(i,D) {
    ans += modpow(mint(2), i) * c[i];
  }
  return ans;
}

int main () {
  cin >> L >> R;

  for(int i = 1; i < D; i++) {
    fact[i] = fact[i-1] * i;
  }
  rep(i,D) ifact[i] = modinv(fact[i]);

  printf("f(%lld) = %d\n", R+1, f(R+1));
  printf("f(%lld) = %d\n", L, f(L));
  cout << f(R+1) - f(L) << endl;
  return 0;
}
