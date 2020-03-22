#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/graph.hpp"

int main() {
  int V, E;
  cin >> V >> E;

  Digraph<Edge> G(V, E);
  rep(i, E) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    G.addUndirectedEdge(Edge(u, v));
  }

  int sq = ceil(sqrt(V));

  vector<int> depth(V, -1);
  vector<bool> independent(V, false);

  function<void(int, int)> printCycle = [&](int s, int u) {
    printf("%d ", u + 1);
    if (u == s) return;

    for (Edge &e : G[u]) {
      if (depth[e.to] == depth[u] - 1) printCycle(s, e.to);
    }
  };

  function<void(int, int)> dfs = [&](int u, int d) {
    depth[u] = d;

    bool ind = true;
    int mind = d, anc = u;
    for (Edge &e : G[u]) {
      if (depth[e.to] == -1) dfs(e.to, d + 1);
      if (depth[e.to] < depth[u]) {
        if (chmin(mind, depth[e.to])) anc = e.to;
        continue;
      }

      ind &= !independent[e.to];
    }
    if (d - mind >= sq - 1) {
      cout << 2 << endl;
      cout << d - mind + 1 << endl;
      printCycle(anc, u);
      exit(0);
    }
    independent[u] = ind;
  };

  dfs(0, 0);

  cout << 1 << endl;
  int c = 0;
  rep(u, V) {
    if (c < sq && independent[u]) {
      printf("%d ", u + 1);
      ++c;
    }
  }
  cout << endl;

  return 0;
}
