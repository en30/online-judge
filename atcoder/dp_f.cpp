#include <bits/stdc++.h>
#include "../include/template"

string s, t;

int main() {
  cin >> s >> t;

  int N = s.size(), M = t.size();

  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

  rep(i, N) rep(j, M) {
    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    if (s[i] == t[j]) {
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
    }
  }

  string ans;
  for (int l = dp[N][M], i = N, j = M; l > 0; --l) {
    while (dp[i][j] >= l) --i;
    while (t[j - 1] != s[i]) --j;
    --j;
    ans = s[i] + ans;
  }
  cout << ans;
  if (ans != "") cout << endl;

  return 0;
}
