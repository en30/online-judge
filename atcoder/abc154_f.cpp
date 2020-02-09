#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int main() {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  Combination<ModInt> comb(r2 + c2 + 2);

  auto g = [&](int i, int j) {
    return (comb.C(i + j + 2, j) * (i + 2) - j - 1) / (j + 1);
  };

  cout << g(r2, c2) - g(r2, c1 - 1) - g(r1 - 1, c2) + g(r1 - 1, c1 - 1) << endl;

  return 0;
}
