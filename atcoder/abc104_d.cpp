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

int main () {
  string S;
  cin >> S;

  vector<vector<mint>> dp(S.size()+1, vector<mint>(4, 0));

  // 0: 全パターン
  // 1: Aを含む
  // 2: ABを含む
  // 3: ABCを含む
  dp[0][0] = 1;
  rep(i,S.size()) {
    if(S[i] == 'A' || S[i] == '?')  {
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][0] + dp[i][1];
      dp[i+1][2] += dp[i][2];
      dp[i+1][3] += dp[i][3];
    }
    if(S[i] == 'B' || S[i] == '?') {
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1];
      dp[i+1][2] += dp[i][1] + dp[i][2];
      dp[i+1][3] += dp[i][3];
    }
    if(S[i] == 'C' || S[i] == '?') {
      dp[i+1][0] += dp[i][0];
      dp[i+1][1] += dp[i][1];
      dp[i+1][2] += dp[i][2];
      dp[i+1][3] += dp[i][3] + dp[i][2];
    }
  }

  cout << dp[S.size()][3] << endl;

  return 0;
}
