#include <bits/stdc++.h>
#include "../include/template"

string A, B;

vector<int> cnt = {0, 0, 0, 0, 1, 1, 1, 1, 1, 2};

int bad(char c) { return c == '4' || c == '9'; }

ll count(string s) {
  int n = s.size();
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  rep(i, n) {
    int d = s[i] - '0';
    dp[i + 1][1][1] = 10 * dp[i][1][1] + 2 * dp[i][1][0] + d * dp[i][0][1] +
                      (d == 0 ? 0 : cnt[d - 1] * dp[i][0][0]);
    dp[i + 1][1][0] =
        8 * dp[i][1][0] + (d == 0 ? 0 : (d - cnt[d - 1]) * dp[i][0][0]);
    dp[i + 1][0][1] = dp[i][0][1] + (bad(s[i])) * dp[i][0][0];
    dp[i + 1][0][0] = (!bad(s[i])) * dp[i][0][0];
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
