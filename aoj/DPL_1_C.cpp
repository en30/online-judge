#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, W;
  cin >> N >> W;

  vector<int> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];

  vector<int> dp(W + 1, 0);
  rep(i, N) rep(j, W + 1) if (j - w[i] >= 0) chmax(dp[j], dp[j - w[i]] + v[i]);
  cout << dp[W] << endl;

  return 0;
}
