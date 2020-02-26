#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<vector<bool>> dp(4, vector<bool>(1000, false));
  dp[0][0] = true;
  rep(i, N) for (int j = 2; j >= 0; --j) for (int k = 99; k >= 0; --k) {
    if (!dp[j][k]) continue;
    dp[j + 1][k * 10 + (S[i] - '0')] = true;
  }

  cout << accumulate(all(dp[3]), 0) << endl;

  return 0;
}
