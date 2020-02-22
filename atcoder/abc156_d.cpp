#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  auto C = [&](int n, int k) {
    ModInt res = 1;
    rep(i, k) res *= (n - i);
    rep(i, k) res /= (i + 1);
    return res;
  };

  ModInt ans = ModInt(2).pow(n) - 1;
  ans = ans - C(n, a) - C(n, b);
  cout << ans << endl;

  return 0;
}
