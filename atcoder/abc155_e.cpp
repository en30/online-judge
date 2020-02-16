#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string N;
  cin >> N;
  N = "0" + N;

  int L = N.size();

  const int INF = 1e9;
  vector<vector<int>> dp(L + 1, vector<int>(2, INF));
  dp[0][0] = 0;
  reverse(all(N));
  rep(i, L) {
    int k = N[i] - '0';
    rep(j, 2) rep(d, 10) {
      int nj = 0, nd = d - j, c = d;
      if (nd < k) {
        nj = 1;
        c += 10 + nd - k;
      } else {
        c += nd - k;
      }

      if (dp[i][j] != INF) chmin(dp[i + 1][nj], dp[i][j] + c);
    }
  }

  cout << dp[L][0] << endl;

  return 0;
}
