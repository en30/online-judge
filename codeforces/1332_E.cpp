#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ModInt::mod(998244353);

  ll n, m, L, R;
  cin >> n >> m >> L >> R;

  if ((n * m) % 2 == 1) {
    cout << ModInt(R - L + 1).pow(n * m) << endl;
    return 0;
  }

  ll nOdd = ((R - (R % 2 == 0)) - (L - (L % 2 == 1)) + 1) / 2;
  ll nEven = (R - L + 1) - nOdd;

  assert(L + nOdd + nEven - 1 == R);
  assert(abs(nOdd - nEven) <= 1);

  cout << (ModInt(R - L + 1).pow(n * m) + ModInt(nEven - nOdd).pow(n * m)) / 2
       << endl;

  return 0;
}
