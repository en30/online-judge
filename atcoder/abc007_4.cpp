#include <bits/stdc++.h>
#include "../include/template"

string A, B;

ll count(string s) {
  int n = s.size();
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  rep(i, n) {
    rep(j, 2) rep(k, 2) {
      int d = s[i] - '0';
      rep(l, (j ? 10 : d + 1)) {
        dp[i + 1][j || l < d][k || l == 4 || l == 9] += dp[i][j][k];
      }
    }
  }

  return dp[n][0][1] + dp[n][1][1];
}

int main() {
  cin >> A >> B;

  ll ans = count(B) - count(A);
  if (A.find("4") != string::npos || A.find("9") != string::npos) ans += 1;
  cout << ans << endl;
  return 0;
}
