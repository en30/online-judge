#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

using mint = ModInt<1000000007>;

int N, M, K;

int main() {
  cin >> N >> M >> K;

  Combination<mint> comb(N * M - 1);

  mint ans = 0;
  rep(i, M) ans += comb.C(N * M - 2, K - 2) * i * (M - i) * N * N;
  rep(i, N) ans += comb.C(N * M - 2, K - 2) * i * (N - i) * M * M;

  cout << ans << endl;
  return 0;
}
