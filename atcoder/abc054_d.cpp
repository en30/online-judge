#include <bits/stdc++.h>
#include "../include/template"

int N, Ma, Mb;
vector<int> a, b, c;

const int W = 401;
int dp[W][W];

int main() {
  cin >> N >> Ma >> Mb;

  a.resize(N), b.resize(N), c.resize(N);
  rep(i, N) cin >> a[i] >> b[i] >> c[i];

  const int INF = 1e9;

  rep(i, N + 1) rep(j, W) rep(k, W) dp[j][k] = INF;
  dp[0][0] = 0;

  rep(i, N) {
    for (int j = W - 1; j >= 0; --j) {
      for (int k = W - 1; k >= 0; --k) {
        if (dp[j][k] == INF) continue;
        dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
        dp[j][k] = min(dp[j][k], dp[j][k]);
      }
    }
  }

  int ans = INF;
  rep(i, W) rep(j, W) {
    if (i == 0 && j == 0) continue;
    if (i * Mb == j * Ma) ans = min(ans, dp[i][j]);
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
