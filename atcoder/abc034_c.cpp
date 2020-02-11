#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int main() {
  int W, H;
  cin >> W >> H;
  Combination<ModInt> comb(W + H);
  cout << comb.C(W + H - 2, W - 1) << endl;

  return 0;
}
