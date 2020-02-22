#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  Combination<ModInt> comb(n);

  ModInt ans = 0;
  for (int i = 0; i <= min(k, n - 1); ++i) {
    ans += comb.C(n, i) * comb.C(n - 1, i);
  }
  cout << ans << endl;

  return 0;
}
