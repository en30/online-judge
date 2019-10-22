#include <bits/stdc++.h>
#include "../include/template"

const ll INF = 1e18;

int N, W;
vector<int> w, v;

int main() {
  cin >> N >> W;
  w.resize(N), v.resize(N);

  rep(i, N) cin >> w[i] >> v[i];

  int V = accumulate(all(v), 0);
  vector<ll> dp(V + 1, INF);
  dp[0] = 0;

  rep(i, N) for (int j = V; j >= 0; --j) {
    if (j - v[i] >= 0) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
  }

  for (int v = V; v >= v; --v) {
    if (dp[v] <= W) {
      cout << v << endl;
      return 0;
    }
  }

  return 0;
}
