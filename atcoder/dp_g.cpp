#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dag.hpp"

int N, M;

int main() {
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(y);
  }

  DAG dag(G);

  vector<int> dp(N, 0);
  for (int u : dag.topologicalSorted) {
    for (int v : G[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }

  cout << *max_element(all(dp)) << endl;

  return 0;
}
