#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  rep(i, N) {
    cin >> x[i];
    x[i] = A - x[i];
  }

  int M = 101, zero = 50 * N;
  // [-50, +50]
  vector<vector<ll>> dp(N + 1, vector<ll>(M * N + 1, 0));
  dp[0][zero] = 1;
  rep(i, N) rep(j, N * M + 1) {
    dp[i + 1][j] = dp[i][j];
    int pj = j - x[i];
    if (0 <= pj && pj <= N * M) dp[i + 1][j] += dp[i][pj];
  }

  cout << dp[N][zero] - 1 << endl;
  return 0;
}
