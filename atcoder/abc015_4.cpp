#include <bits/stdc++.h>
#include "../include/template"

int W, N, K;

int main() {
  cin >> W >> N >> K;

  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  vector<vector<int>> dp(W + 1, vector<int>(K + 1, 0));
  rep(i, N) for (int j = W; j >= 0; --j) for (int k = K; k >= 0; --k) {
    if (j - A[i] >= 0 && k - 1 >= 0)
      dp[j][k] = max(dp[j][k], dp[j - A[i]][k - 1] + B[i]);
  }

  cout << dp[W][K] << endl;

  return 0;
}
