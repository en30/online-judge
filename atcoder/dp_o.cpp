#include <bits/stdc++.h>
#include "../include/template"
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
    int s = (1 << (i + 1)) - 1;
    while (s < (1 << N)) {
      rep(j, N) {
        if (((s >> j) & 1) && a[i][j]) dp[i + 1][s] += dp[i][s & ~(1 << j)];
      }

      int x = s & -s, y = s + x;
      s = (((s & ~y) / x) >> 1) | y;
    }
  }

  mint ans = 0;
  rep(s, 1 << N) ans += dp[N][s];
  cout << ans << endl;
  return 0;
}
