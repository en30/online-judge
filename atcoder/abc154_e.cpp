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
    int nd = N[i] - '0';
    rep(d, 10) {
      int ni = i + 1, nj = j, nk = k;
      if (d != 0) ++nj;
      if (k == 0) {
        if (d > nd) continue;
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  cout << dp[M][K][0] + dp[M][K][1] << endl;
  return 0;
}
