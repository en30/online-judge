#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt<1000000007>;

int N, M, K;

int main() {
  cin >> N >> M >> K;

  vector<mint> fact(N * M - 1), ifact(N * M - 1);
  fact[0] = 1;
  rep(i, N * M - 2) fact[i + 1] = fact[i] * (i + 1);
  rep(i, N * M - 1) ifact[i] = fact[i].inverse();

  auto comb = [&](int n, int k) { return fact[n] * ifact[k] * ifact[n - k]; };

  mint ans = 0;
  rep(i, M) ans += comb(N * M - 2, K - 2) * i * (M - i) * N * N;
  rep(i, N) ans += comb(N * M - 2, K - 2) * i * (N - i) * M * M;

  cout << ans << endl;
  return 0;
}
