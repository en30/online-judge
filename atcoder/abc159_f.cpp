#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ModInt::mod(998244353);

  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  enum State {
    PENDING,
    OPEN,
    CLOSED,
  };
  vector<vector<vector<ModInt>>> dp(
      N + 1, vector<vector<ModInt>>(S + 1, vector<ModInt>(3, 0)));
  dp[0][0][PENDING] = 1;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < S + 1; ++j) {
      dp[i + 1][j][CLOSED] += dp[i][j][CLOSED];

      // i not in X
      dp[i + 1][j][OPEN] += dp[i][j][OPEN];
      dp[i + 1][j][CLOSED] += dp[i][j][OPEN];
      // i in X
      if (j - A[i] >= 0) {
        dp[i + 1][j][OPEN] += dp[i][j - A[i]][OPEN];
        dp[i + 1][j][CLOSED] += dp[i][j - A[i]][OPEN];
      }

      // i not in X
      dp[i + 1][j][PENDING] += dp[i][j][PENDING];
      dp[i + 1][j][OPEN] += dp[i][j][PENDING];
      // i in X
      if (j - A[i] >= 0) {
        dp[i + 1][j][OPEN] += dp[i][j - A[i]][PENDING];
        dp[i + 1][j][CLOSED] += dp[i][j - A[i]][PENDING];
      }
    }
  }

  cout << dp[N][S][CLOSED] << endl;
  return 0;
}
