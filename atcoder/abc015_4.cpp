#include <bits/stdc++.h>
#include "../include/template"

int W, N, K;

int main() {
  cin >> W >> N >> K;

  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  vector<vector<vector<int>>> dp(
      N + 1, vector<vector<int>>(W + 1, vector<int>(K + 1, 0)));
  rep(i, N) rep(j, W + 1) rep(k, K + 1) {
    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
    if (j - A[i] >= 0 && k + 1 <= K)
      dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j - A[i]][k] + B[i]);
  }

  cout << dp[N][W][K] << endl;

  return 0;
}
