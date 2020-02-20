#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  rep(i, N) cin >> x[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(A * N + 1, 0));
  dp[0][0] = 1;
  rep(i, N) for (int j = N; j >= 0; --j) for (int k = A * N; k >= 0; --k) {
    if (j + 1 <= N && k + x[i] <= A * N) dp[j + 1][k + x[i]] += dp[j][k];
  }

  ll ans = 0;
  for (int n = 1; n <= N; ++n) ans += dp[n][n * A];
  cout << ans << endl;
  return 0;
}
