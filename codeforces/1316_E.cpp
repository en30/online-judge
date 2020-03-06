#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, p, k;
  cin >> n >> p >> k;

  vector<vector<int>> s(n, vector<int>(p + 1));
  rep(i, n) cin >> s[i][p];
  rep(i, n) rep(j, p) cin >> s[i][j];

  sort(s.rbegin(), s.rend(),
       [&](const vector<int>& a, const vector<int>& b) { return a[p] < b[p]; });

  vector<vector<ll>> dp(n + 1, vector<ll>(1 << p, -1));

  dp[0][0] = 0;
  rep(i, n) rep(team, (1 << p)) {
    if (dp[i][team] == -1) continue;
    chmax(dp[i + 1][team],
          dp[i][team] + (i - __builtin_popcount(team) < k ? s[i][p] : 0));
    rep(j, p) if (!((team >> j) & 1)) {
      chmax(dp[i + 1][team | (1 << j)], dp[i][team] + s[i][j]);
    }
  }

  cout << dp[n][(1 << p) - 1] << endl;

  return 0;
}
