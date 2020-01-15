#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"
#include "../include/mod.hpp"
using mint = ModInt;

int N;
vector<vector<int>> a;

int main() {
  cin >> N;
  a.resize(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> a[i][j];

  vector<vector<mint>> dp(N + 1, vector<mint>(1 << N, 0));

  dp[0][0] = 1;

  rep(i, N) {
    int s = first_fixed_size_subset(N, i + 1);
    do {
      rep(j, N) {
        if (((s >> j) & 1) && a[i][j]) dp[i + 1][s] += dp[i][s & ~(1 << j)];
      }
    } while (next_fixed_size_subset(N, i + 1, s));
  }

  mint ans = 0;
  rep(s, 1 << N) ans += dp[N][s];
  cout << ans << endl;
  return 0;
}
