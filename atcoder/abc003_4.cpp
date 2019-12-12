#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;
int R, C, X, Y, D, L;

int main() {
  cin >> R >> C >> X >> Y >> D >> L;

  vector<mint> fact(X * Y + 1, 1), ifact(X * Y + 1, 1);
  for (int i = 2; i <= X * Y; ++i) {
    fact[i] = fact[i - 1] * i;
    ifact[i] = fact[i].inverse();
  }

  auto numWithoutSpaces = [&](int n) {
    int M = X * Y - n;
    if (D + L > M) return mint(0);
    return fact[M] * ifact[D] * ifact[L] * ifact[M - D - L];
  };

  mint ans = numWithoutSpaces(0);

  if (X != 1 && Y != 1) {
    ans -= numWithoutSpaces(X) * 2 + numWithoutSpaces(Y) * 2;
    ans += numWithoutSpaces(X + Y - 1) * 4 + numWithoutSpaces(2 * X) +
           numWithoutSpaces(2 * Y);
    ans -= numWithoutSpaces(2 * X + Y - 2) * 2 +
           numWithoutSpaces(X + 2 * Y - 2) * 2;
    ans += numWithoutSpaces(2 * X + 2 * Y - 4);
  } else if (X == 1 || Y == 1) {
    ans -= numWithoutSpaces(1) * 2;
    ans += numWithoutSpaces(2);
  }

  ans *= (R - X + 1) * (C - Y + 1);
  cout << ans << endl;
  return 0;
}
