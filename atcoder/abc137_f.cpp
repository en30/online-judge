#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int p;

int main() {
  cin >> p;
  ModInt::mod(p);
  using mint = ModInt;

  vector<mint> b(p, 0);
  int a;

  vector<mint> fact(p), ifact(p);
  fact[0] = 1;
  rep(i, p) {
    if (i + 1 < p) fact[i + 1] = fact[i] * (i + 1);
    ifact[i] = fact[i].inverse();
  }

  rep(i, p) {
    cin >> a;
    if (a) {
      b[0] += 1;
      mint k = 1;
      for (int j = p - 1; j >= 0; --j) {
        b[j] -= fact[p - 1] * ifact[p - 1 - j] * ifact[j] * k;
        k *= -i;
      }
    }
  }

  rep(i, p) {
    if (i != 0) cout << " ";
    cout << b[i];
  }
  cout << endl;

  return 0;
}
