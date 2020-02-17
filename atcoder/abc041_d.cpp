#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[y].push_back(x);
  }

  vector<int> preCond(N, -1);
  function<int(int)> dfs = [&](int u) {
    if (preCond[u] != -1) return preCond[u];
    int res = 0;
    for (int v : G[u]) res |= (1 << v) | dfs(v);
    return preCond[u] = res;
  };

  rep(i, N) if (preCond[i] == -1) dfs(i);

  vector<vector<ll>> dp(N + 1, vector<ll>(1 << N, 0));
  dp[0][0] = 1;
  rep(i, N) rep(s, 1 << N) rep(u, N) {
    if ((s & preCond[u]) == preCond[u]) dp[i + 1][s | (1 << u)] += dp[i][s];
  }

  cout << dp[N][(1 << N) - 1] << endl;

  return 0;
}
