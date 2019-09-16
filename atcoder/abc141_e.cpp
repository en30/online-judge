#include <bits/stdc++.h>
#include "../include/template"

int N;
string S;

int main() {
  cin >> N >> S;

  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

  for (int i = N - 1; i >= 0; --i) {
    for (int j = N - 1; j >= 0; --j) {
      if (S[i] == S[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
    }
  }

  int ans = 0;
  rep(i, N) rep(j, N) {
    if (i >= j) continue;
    ans = max(ans, min(dp[i][j], j - i));
  }

  cout << ans << endl;

  return 0;
}
