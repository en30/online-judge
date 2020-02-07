#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string N;
  cin >> N;
  const int M = N.size();
  vector<vector<vector<int>>> dp(
      2, vector<vector<int>>(M + 1, vector<int>(10, 0)));
  dp[0][0][0] = 1;
  rep(i, M) {
    int m = N[i] - '0';
    rep(k, 10) {
      if (k + (m == 1) < 10) dp[0][i + 1][k + (m == 1)] += dp[0][i][k];
      dp[1][i + 1][k] += (m - (m > 1)) * dp[0][i][k];
      if (m > 1) dp[1][i + 1][k + 1] += dp[0][i][k];
      dp[1][i + 1][k] += 9 * dp[1][i][k];
      dp[1][i + 1][k + 1] += dp[1][i][k];
    }
  }

  int ans = 0;
  rep(i, 2) rep(j, 10) ans += j * dp[i][M][j];
  cout << ans << endl;

  return 0;
}
