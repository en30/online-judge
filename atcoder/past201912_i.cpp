#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;

  vector<int> S(M, 0), C(M);

  rep(i, M) {
    rep(j, N) {
      char c;
      cin >> c;
      if (c == 'Y') {
        S[i] |= 1 << j;
      }
    }
    cin >> C[i];
  }

  const ll INF = 1e15;
  vector<vector<ll>> dp(M + 1, vector<ll>(1 << N, INF));
  dp[0][0] = 0;
  rep(i, M) rep(s, (1 << N)) {
    dp[i + 1][s] = min(dp[i + 1][s], dp[i][s]);
    dp[i + 1][s | S[i]] = min(dp[i + 1][s | S[i]], dp[i][s] + C[i]);
  }

  if (dp[M][(1 << N) - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << dp[M][(1 << N) - 1] << endl;
  }

  return 0;
}
