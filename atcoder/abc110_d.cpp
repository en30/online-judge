#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"
#include "../include/prime.hpp"

using mint = ModInt<1000000007>;

int main() {
  int N, M;
  cin >> N >> M;

  int K = N + 40;

  Combination<mint> comb(K);

  mint ans = 1;
  auto facts = Prime::factorize(M);
  for (auto f : facts) {
    ans *= comb.H(N, f.r);
  }

  cout << ans << endl;

  return 0;
}
