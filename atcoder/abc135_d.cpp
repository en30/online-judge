#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<mint>> dp(N + 1, vector<mint>(13, 0));
  dp[0][0] = 1;

  int r = 1;
  rep(i, N) {
    if (S[N - 1 - i] == '?') {
      rep(k, 10) {
        int d = (k * r) % 13;
        rep(j, 13) { dp[i + 1][(j + d) % 13] += dp[i][j]; }
      }
    } else {
      int d = ((S[N - 1 - i] - '0') * r) % 13;
      rep(j, 13) { dp[i + 1][(j + d) % 13] += dp[i][j]; }
    }
    r *= 10;
    r %= 13;
  }

  cout << dp[N][5] << endl;

  return 0;
}
