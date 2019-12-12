#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

string K;
int D;

int main() {
  cin >> K >> D;
  int N = K.size();

  vector<vector<vector<mint>>> dp(N + 1,
                                  vector<vector<mint>>(D, vector<mint>(2, 0)));
  dp[0][0][1] = 1;

  rep(i, N) {
    int m = K[i] - '0';
    rep(j, D) {
      dp[i + 1][j][1] = dp[i][(j - m + 10 * D) % D][1];
      rep(l, 10) {
        dp[i + 1][j][0] += dp[i][(j - l + 10 * D) % D][0];
        if (l < m) dp[i + 1][j][0] += dp[i][(j - l + 10 * D) % D][1];
      }
    }
  }

  cout << dp[N][0][0] + dp[N][0][1] - 1 << endl;

  return 0;
}
