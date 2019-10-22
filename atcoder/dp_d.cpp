#include <bits/stdc++.h>
#include "../include/template"

int N, W;
vector<int> w, v;

int main() {
  cin >> N >> W;
  w.resize(N), v.resize(N);

  rep(i, N) cin >> w[i] >> v[i];

  vector<ll> dp(W + 1, 0);

  rep(i, N) for (int j = W; j >= 0; --j) {
    if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  }

  cout << dp[W] << endl;
  return 0;
}
