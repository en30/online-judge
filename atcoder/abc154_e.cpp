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

  rep(i, M) rep(j, K + 1) rep(k, 2) {
    int d = N[i] - '0';
    rep(l, (k ? 10 : d + 1)) {
      dp[i + 1][j + (l != 0)][k | (l < d)] += dp[i][j][k];
    }
  }

  cout << dp[M][K][0] + dp[M][K][1] << endl;
  return 0;
}
