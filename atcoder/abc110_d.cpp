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
  friend constexpr Fp<MOD> modinv(const Fp<MOD> &a) noexcept {
    return modpow(a, MOD - 2);
  }
};

using mint = Fp<MOD>;

struct primeFactor {
  int p, r;
};

vector<primeFactor> factorization(int n) {
  vector<primeFactor> res;
  int m = n;
  for(int i = 2; i*i <= m; i++) {
    if(m % i) continue;
    primeFactor f = primeFactor{i,0};
    while(m % i == 0) {
      m /= i;
      f.r++;
    }
    res.push_back(f);
  }
  if(m != 1) {
    res.push_back(primeFactor{m,1});
  }
  return res;
}

int main () {
  int N, M;
  cin >> N >> M;

  int K = N + 40;

  vector<mint> fact(K+1, 1), ifact(K+1, 1);
  for(int i = 1; i <= K; i++) {
    fact[i] = fact[i-1] * i;
    ifact[i] = modinv(fact[i]);
  }

  mint ans = 1;
  auto facts = factorization(M);
  for(auto f: facts) {
    ans *= fact[f.r+N-1] * ifact[N-1] * ifact[f.r];
  }

  cout << ans << endl;

  return 0;
}
