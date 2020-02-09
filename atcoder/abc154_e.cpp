#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string N;
  cin >> N;
  int K;
  cin >> K;

  const int M = N.size();
  vector<vector<vector<ll>>> dp(M + 1,
                                vector<vector<ll>>(K + 2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  rep(i, M) rep(j, K + 1) {
    dp[i + 1][j + (N[i] != '0')][0] += dp[i][j][0];
    if (N[i] != '0') dp[i + 1][j][1] += dp[i][j][0];
    dp[i + 1][j + 1][1] += (N[i] - '0' - (N[i] >= '1')) * dp[i][j][0];
    dp[i + 1][j][1] += dp[i][j][1];
    dp[i + 1][j + 1][1] += 9 * dp[i][j][1];
  }

  cout << dp[M][K][0] + dp[M][K][1] << endl;
  return 0;
}
