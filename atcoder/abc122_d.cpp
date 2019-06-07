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

// A  C  G  T
// 00 01 10 11

// .A.G.C.
// ?AGC A?GC ?GAC ?ACG AG?C

int masks[5]    = { 0b00111111, 0b11001111, 0b00111111, 0b00111111, 0b11110011 };
int patterns[5] = { 0b00001001, 0b00001001, 0b00100001, 0b00000110, 0b00100001 };

const int S = 4*4*4;

bool ok(int s) {
  rep(i,5) {
    if((s & masks[i]) == patterns[i]) {
      return false;
    }
  }
  return true;
}

int main () {
  int n;
  cin >> n;
  using mint = Fp<MOD>;

  vector<vector<mint>> dp(S, vector<mint>(n+1, 0));
  dp[0b111111][0] = 1;

  rep(i,n) {
    rep(j, S) {
      rep(k, 4) {
        int s = (j << 2) | k;
        if(ok(s)) {
          dp[s & 0b111111][i+1] += dp[j][i];
        }
      }
    }
  }

  mint ans  = 0;
  rep(i,S) ans += dp[i][n];
  cout << ans << endl;

  return 0;
}
