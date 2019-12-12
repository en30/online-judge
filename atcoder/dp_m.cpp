#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N, K;
vector<int> a;

int main() {
  cin >> N >> K;
  a.resize(N);
  rep(i, N) cin >> a[i];

  vector<vector<mint>> dp(N + 1, vector<mint>(K + 2, 0));
  dp[0][0] = 1;

  rep(i, N) {
    rep(k, K + 1) dp[i][K - k + 1] = dp[i][K - k];
    rep(k, K + 1) dp[i][k + 1] += dp[i][k];

    rep(k, K + 1) { dp[i + 1][k] = dp[i][k + 1] - dp[i][k - min(a[i], k)]; }
  }

  cout << dp[N][K] << endl;
  return 0;
}
