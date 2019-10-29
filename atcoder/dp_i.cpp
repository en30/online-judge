#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<double> p;

int main() {
  cin >> N;
  p.resize(N);
  rep(i, N) cin >> p[i];

  vector<vector<double>> dp(2, vector<double>(N + 1, 0.0));
  dp[0][0] = 1.0;

  rep(i, N) rep(j, N + 1) {
    int curr = i % 2;
    int next = (i + 1) % 2;

    dp[next][j] = (1.0 - p[i]) * dp[curr][j];
    if (j > 0) dp[next][j] += p[i] * dp[curr][j - 1];
  }

  double ans = 0.0;

  for (int i = (N + 1) / 2; i <= N; ++i) ans += dp[N % 2][i];

  cout << setprecision(10) << ans << endl;

  return 0;
}
