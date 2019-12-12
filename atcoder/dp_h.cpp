#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int H, W;

int main() {
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> a[i][j];

  vector<mint> dp(W, 0);
  dp[0] = 1;

  rep(i, H) rep(j, W) {
    if (a[i][j] == '#') {
      dp[j] = 0;
    } else if (j > 0) {
      dp[j] += dp[j - 1];
    };
  }

  cout << dp[W - 1] << endl;

  return 0;
}
