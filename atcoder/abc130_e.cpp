#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;
int N, M;
vector<int> S, T;
int main() {
  cin >> N >> M;
  S.resize(N), T.resize(M);
  rep(i, N) cin >> S[i];
  rep(i, M) cin >> T[i];

  vector<vector<mint>> dp(N + 1, vector<mint>(M + 1, 0));

  rep(i, N) rep(j, M) {
    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
    if (S[i] == T[j]) dp[i + 1][j + 1] += dp[i][j] + 1;
  }

  cout << dp[N][M] + 1 << endl;

  return 0;
}
