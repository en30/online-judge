#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  const int K = 21;
  vector<vector<ll>> dp(N - 1, vector<ll>(K, 0));
  dp[0][a[0]] = 1;

  rep(i, N - 2) rep(j, K) {
    if (j - a[i + 1] >= 0) dp[i + 1][j] += dp[i][j - a[i + 1]];
    if (j + a[i + 1] < K) dp[i + 1][j] += dp[i][j + a[i + 1]];
  }

  cout << dp[N - 2][a[N - 1]] << endl;

  return 0;
}
