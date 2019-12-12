#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N, K;

mint dp[51][51][2501];

int main() {
  cin >> N >> K;

  dp[0][0][0] = 1;
  rep(i, N) {
    rep(j, i + 1) rep(k, K + 1) {
      dp[i + 1][j][k + 2 * j] += dp[i][j][k] * (2 * j + 1);
      if (j > 0) dp[i + 1][j - 1][k + 2 * (j - 1)] += dp[i][j][k] * j * j;
      dp[i + 1][j + 1][k + 2 * (j + 1)] += dp[i][j][k];
    }
  }

  cout << dp[N][0][K] << endl;
  return 0;
}
