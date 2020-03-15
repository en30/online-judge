#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int q;
  cin >> q;

  rep(i, q) {
    string X, Y;
    cin >> X >> Y;

    int M = X.size(), N = Y.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    rep(i, M) rep(j, N) {
      if (X[i] == Y[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      chmax(dp[i + 1][j + 1], max(dp[i][j + 1], dp[i + 1][j]));
    }
    cout << dp[M][N] << endl;
  }

  return 0;
}
