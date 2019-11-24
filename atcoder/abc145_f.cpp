#include <bits/stdc++.h>
#include "../include/template"

int N, K;
vector<int> H;

int main() {
  cin >> N >> K;
  H.resize(N + 1, 0);
  rep(i, N) cin >> H[i + 1];

  const ll INF = 1e18;
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 2, INF));

  dp[0][1] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N + 1; ++j) {
      for (int k = 0; k < i; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0, H[i] - H[k]));
      }
    }
  }

  ll ans = INF;
  rep(i, N + 1) ans = min(ans, dp[i][N - K + 1]);
  cout << ans << endl;

  return 0;
}
