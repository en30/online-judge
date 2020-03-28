#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bfs_shortest_path.hpp"

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  --X, --Y;

  Digraph<Edge> G(N);
  rep(i, N - 1) { G.addUndirectedEdge(Edge(i, i + 1)); }
  G.addUndirectedEdge(Edge(X, Y));

  vector<int> ans(N, 0);
  rep(i, N) {
    BFSShortestPath sp(G, i);
    rep(j, N)++ ans[sp.distTo(j)];
  }

  rep(i, N - 1) cout << ans[i + 1] / 2 << endl;

  return 0;
}
