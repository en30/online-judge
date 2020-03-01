#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/graph.hpp"

int main() {
  int n;
  cin >> n;

  Digraph<Edge> G(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    --u;
    rep(j, k) {
      int v;
      cin >> v;
      --v;
      G.addEdge(Edge(u, v));
    }
  }

  vector<int> d(n, -1), f(n);
  function<int(int, int)> dfs = [&](int u, int t) {
    d[u] = t;
    for (Edge &e : G[u]) {
      if (d[e.to] != -1) continue;
      t = dfs(e.to, t + 1);
    }
    return f[u] = t + 1;
  };

  int t = 0;
  rep(i, n) {
    if (d[i] == -1) t = dfs(i, t + 1);
  }

  rep(i, n) { cout << i + 1 << " " << d[i] << " " << f[i] << endl; }

  return 0;
}
