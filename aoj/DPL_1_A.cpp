#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  rep(i, m) cin >> c[i];

  vector<int> dp(n + 1, 1e9);
  dp[0] = 0;

  rep(i, m) rep(j, n + 1) if (j - c[i] >= 0) chmin(dp[j], dp[j - c[i]] + 1);
  cout << dp[n] << endl;

  return 0;
}
