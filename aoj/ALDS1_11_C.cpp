#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bfs_shortest_path.hpp"

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

  BFSShortestPath sp(G, 0);
  rep(i, n) {
    cout << i + 1 << " " << (sp.hasPathTo(i) ? sp.distTo(i) : -1) << endl;
  }

  return 0;
}
