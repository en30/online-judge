#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  vector<vector<int>> G(N);
  vector<bitset<20>> C(N - 1, 0);
  unordered_map<int, unordered_map<int, int>> edge;
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
    edge[a][b] = i;
    edge[b][a] = i;
  }

  int M;
  cin >> M;

  function<bool(int, int, int, int)> append = [&](int u, int v, int p, int c) {
    if (u == v) return true;

    bool found = false;
    for (auto w : G[u]) {
      if (w == p) continue;
      bool goodPath = append(w, v, u, c);
      if (goodPath) C[edge[u][w]].set(c);
      found |= goodPath;
    }
    return found;
  };

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    append(u, v, -1, i);
  }

  vector<vector<ll>> dp((1 << M), vector<ll>(N, 0));
  dp[0][0] = 1;
  rep(i, N - 1) rep(s, (1 << M)) {
    dp[s | int(C[i].to_ulong())][i + 1] += dp[s][i];  // B
    dp[s][i + 1] += dp[s][i];                         // W
  }

  cout << dp[(1 << M) - 1][N - 1] << endl;

  return 0;
}
