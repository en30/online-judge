#include <bits/stdc++.h>
#include "../include/template"

using usage = bitset<400>;
void solve() {
  string s, t;
  cin >> s >> t;

  int N = s.size(), M = t.size();

  for (int i = 1; i <= M; ++i) {
    vector<vector<int>> dp(N + 1, vector<int>(i + 1, -1));
    dp[0][0] = 0;
    rep(j, N) rep(k, i + 1) {
      chmax(dp[j + 1][k], dp[j][k]);
      if (k + 1 < i + 1 && s[j] == t[k]) chmax(dp[j + 1][k + 1], dp[j][k]);
      if (dp[j][k] != -1 && s[j] == t[i + dp[j][k]])
        chmax(dp[j + 1][k], dp[j][k] + 1);
    }

    if (dp[N][i] == M - i) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) solve();
  return 0;
}
