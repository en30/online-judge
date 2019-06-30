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

int N, K, M;
vector<vector<mint>> bit;

void add(int i, int a, mint w) {
  for (int x = a; x <= M; x += x & -x) bit[i][x] += w;
}

mint sum(int i, int a) {
  mint ret = 0;
  for (int x = a; x > 0; x -= x & -x) ret += bit[i][x];
  return ret;
}

int main () {

  cin >> N >> K;

  vector<int> r;

  for(int i = 1;; ) {
    int j = N/(N/i) + 1;
    r.push_back(j - i);

    i = j;
    if(i > N) break;
  }

  M = r.size();
  bit = vector<vector<mint>>(K+1, vector<mint>(M+1, 0));

  for(int i = 0; i < M; i++) add(1, i+1, r[i]);

  for(int i = 1; i < K; i++) {
    for(int j = 0; j < M; j++) {
      add(i+1, j+1, sum(i, M-j)*r[j]);
    }
  }

  cout << sum(K, M) << endl;

  return 0;
}
