#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int X, Y;

mint comb(int n, int k) {
  mint res = 1;
  rep(i, k) res *= (n - i);
  rep(i, k) res /= (i + 1);
  return res;
}

int main() {
  cin >> X >> Y;

  int k = (X + Y) / 3;

  if ((X + Y) % 3 != 0 || X < k || X > 2 * k) {
    cout << 0 << endl;
    return 0;
  }

  cout << comb(k, X - k) << endl;

  return 0;
}
