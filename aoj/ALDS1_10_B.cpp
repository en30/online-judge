#include <bits/stdc++.h>
#include "../include/template"

struct Size {
  int r, c;
};

int main() {
  int n;
  cin >> n;
  vector<Size> M(n);
  rep(i, n) cin >> M[i].r >> M[i].c;

  const int INF = 1e9;
  vector<vector<int>> dp(n, vector<int>(n, INF));
  rep(i, n) dp[i][i] = 0;

  for (int l = 2; l <= n; ++l) {
    rep(i, n) {
      int j = i + l - 1;
      if (j >= n) continue;
      for (int k = i; k + 1 <= j; ++k) {
        chmin(dp[i][j], dp[i][k] + dp[k + 1][j] + M[i].r * M[k].c * M[j].c);
      }
    }
  }

  cout << dp[0][n - 1] << endl;

  return 0;
}
