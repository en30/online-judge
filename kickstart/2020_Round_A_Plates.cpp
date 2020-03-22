#include <bits/stdc++.h>
#include "../include/template"

int solve() {
  int N, K, P;
  cin >> N >> K >> P;
  vector<vector<int>> B(N, vector<int>(K));
  rep(i, N) rep(j, K) cin >> B[i][j];

  const int INF = 1e9;
  vector<vector<int>> dp(N + 1, vector<int>(P + 1, 0));
  dp[0][0] = 0;

  rep(i, N) rep(j, P + 1) {
    int s = 0;
    chmax(dp[i + 1][j], dp[i][j]);
    rep(k, K) {
      s += B[i][k];
      if (j - k - 1 >= 0) chmax(dp[i + 1][j], dp[i][j - k - 1] + s);
    }
  }
  return dp[N][P];
}

int main() {
  int T;
  cin >> T;
  rep(i, T) cout << "Case #" << i + 1 << ": " << solve() << endl;
  return 0;
}
