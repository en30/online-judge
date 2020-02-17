#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  Combination<ModInt> comb(H + W);

  auto move = [&](int r1, int c1, int r2, int c2) {
    return comb.C(r2 - r1 + c2 - c1, r2 - r1);
  };

  ModInt ans = move(0, 0, H - 1, W - 1);
  rep(i, B) ans -= move(0, 0, H - 1 - A, i) * move(H - A, i, H - 1, W - 1);

  cout << ans << endl;

  return 0;
}
