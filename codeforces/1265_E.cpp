#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt<998244353>;

int n;
vector<int> p;
vector<mint> P;

int main() {
  cin >> n;
  p.resize(n);
  P.resize(n + 1);

  rep(i, n) cin >> p[i];

  P[0] = 1;
  rep(i, n) P[i + 1] = P[i] * p[i] / 100;

  mint ans = 0;
  rep(i, n + 1) ans += P[i];
  ans /= P[n];
  cout << ans - 1 << endl;
  return 0;
}
