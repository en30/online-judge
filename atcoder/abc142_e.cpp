#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<int> a, f;

int main() {
  cin >> N >> M;
  a.resize(M), f.resize(M, 0);

  rep(i, M) {
    int b;
    cin >> a[i] >> b;
    rep(j, b) {
      int c;
      cin >> c;
      f[i] |= (1 << (c - 1));
    }
  }

  int K = (1 << N);
  const int INF = 1e9;
  vector<vector<int>> dp(M + 1, vector<int>(K, INF));
  dp[0][0] = 0;
  rep(i, M) rep(k, K) {
    dp[i + 1][k] = min(dp[i + 1][k], dp[i][k]);
    dp[i + 1][k | f[i]] = min(dp[i + 1][k | f[i]], dp[i][k] + a[i]);
  }

  cout << (dp[M][K - 1] == INF ? -1 : dp[M][K - 1]) << endl;
  return 0;
}
