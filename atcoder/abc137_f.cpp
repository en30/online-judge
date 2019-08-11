#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int p;
int MOD;

struct mint {
  long long val;
  mint(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) v += MOD;
  }
  int getmod() { return MOD; }
  mint operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  mint operator + (const mint& r) const noexcept { return mint(*this) += r; }
  mint operator - (const mint& r) const noexcept { return mint(*this) -= r; }
  mint operator * (const mint& r) const noexcept { return mint(*this) *= r; }
  mint operator / (const mint& r) const noexcept { return mint(*this) /= r; }
  mint& operator += (const mint& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  mint& operator -= (const mint& r) noexcept {
    val -= r.val;
    if (val >= MOD) val -= MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  mint& operator *= (const mint& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  mint& operator /= (const mint& r) noexcept {
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
  bool operator == (const mint& r) const noexcept {
    return this->val == r.val;
  }
  bool operator != (const mint& r) const noexcept {
    return this->val != r.val;
  }
  friend ostream& operator << (ostream &os, const mint& x) noexcept {
    return os << x.val;
  }
  friend istream& operator >> (istream &is, mint& x) noexcept {
    return is >> x.val;
  }
  friend mint modpow(const mint &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
  friend mint modinv(const mint &a) noexcept {
    return modpow(a, MOD - 2);
  }
};

int main () {
  cin >> p;
  MOD = p;

  vector<mint> b(p, 0);
  int a;

  vector<mint> fact(p), ifact(p);
  fact[0] = 1;
  rep(i,p) {
    if(i + 1 < p) fact[i+1] = fact[i] * (i+1);
    ifact[i] = modinv(fact[i]);
  }

  rep(i,p) {
    cin >> a;
    if(a) {
      b[0] += 1;
      mint k = 1;
      for(int j = p-1; j >= 0; --j) {
        b[j] -= fact[p-1] * ifact[p-1-j] * ifact[j] * k;
        k *= -i;
      }
    }
  }

  rep(i,p) {
    if(i != 0) cout << " ";
    cout << b[i];
  }
  cout << endl;

  return 0;
}
