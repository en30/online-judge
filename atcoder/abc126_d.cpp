#include <bits/stdc++.h>
#include "../include/template"

int N;

struct Edge {
  int to, w;
};

vector<vector<Edge>> G;
vector<int> ans;

void dfs(int d, int u, int p) {
  ans[u] = d;

  for (Edge& e : G[u]) {
    if (e.to == p) continue;
    dfs((d + e.w) % 2, e.to, u);
  }
}

int main() {
  cin >> N;
  G.resize(N);
  ans.resize(N);

  rep(i, N - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    G[u].push_back(Edge{v, w});
    G[v].push_back(Edge{u, w});
  }

  dfs(0, 0, -1);

  rep(i, N) cout << ans[i] << endl;

  return 0;
}
