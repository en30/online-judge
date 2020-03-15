#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  rep(i, N) cin >> v[i] >> w[i];

  vector<int> dp(W + 1, 0);
  rep(i, N) for (int j = W; j >= 0; --j) {
    if (j - w[i] >= 0) chmax(dp[j], dp[j - w[i]] + v[i]);
  }

  cout << dp[W] << endl;

  return 0;
}
