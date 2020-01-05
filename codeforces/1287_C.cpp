#include <bits/stdc++.h>
#include "../include/template"

int n;

int main() {
  cin >> n;
  vector<int> p(n);

  int m = 0;
  rep(i, n) {
    cin >> p[i];
    if (p[i] == 0) ++m;
  }

  int n0 = n / 2, n1 = (n + 1) / 2;
  rep(i, n) {
    if (p[i] == 0) continue;
    (p[i] % 2 == 0 ? n0 : n1) -= 1;
  }

  assert(n0 + n1 == m);

  const int INF = 1e9;
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(n0 + 1, vector<int>(2, INF)));

  if (p[0] == 0) {
    dp[0][n0][1] = 0;
    dp[0][n0 - 1][0] = 0;
  } else {
    dp[0][n0][p[0] % 2] = 0;
  }

  for (int i = 1; i <= n - 1; ++i) rep(j, n0 + 1) {
      if (p[i] == 0) {
        // 0
        if (j + 1 <= n0)
          dp[i][j][0] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1] + 1);

        // 1
        dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
      } else {
        int pc = p[i] % 2;
        dp[i][j][!pc] = INF;
        dp[i][j][pc] = min(dp[i - 1][j][0] + pc, dp[i - 1][j][1] + !pc);
      }
    }

  cout << min(dp[n - 1][0][0], dp[n - 1][0][1]) << endl;
  return 0;
}
