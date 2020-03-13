#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> dp(n + 1, vector<int>(h, -1));
  dp[0][0] = 0;
  rep(i, n) rep(j, h) {
    if (dp[i][j] == -1) continue;
    int nj = (j + a[i]) % h;
    chmax(dp[i + 1][nj], dp[i][j] + (l <= nj && nj <= r));
    nj = (nj - 1 + h) % h;
    chmax(dp[i + 1][nj], dp[i][j] + (l <= nj && nj <= r));
  }
  
  cout << *max_element(all(dp[n])) << endl;

  return 0;
}
