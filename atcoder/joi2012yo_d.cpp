#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ModInt::mod(10000);

  int N, K;
  cin >> N >> K;

  map<int, int> res;
  rep(i, K) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    res[A] = B;
  }

  const int P = 3, M = 3;
  vector<vector<vector<ModInt>>> dp(
      N + 1, vector<vector<ModInt>>(P, vector<ModInt>(M, 0)));
  dp[0][0][0] = 1;

  rep(i, N) rep(j, P) rep(k, M) rep(l, P) {
    if (res.find(i) != res.end() && res[i] != l) continue;
    if (j == l) {
      if (k + 1 < M) dp[i + 1][j][k + 1] += dp[i][j][k];
    } else {
      dp[i + 1][l][1] += dp[i][j][k];
    }
  }

  ModInt ans = 0;
  rep(j, P) rep(k, M) ans += dp[N][j][k];
  cout << ans << endl;

  return 0;
}
