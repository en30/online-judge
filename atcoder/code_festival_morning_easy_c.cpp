#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;

  using Edge = WeightedEdge<int>;
  Digraph<Edge> G(n);
  rep(i, m) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
  }

  Dijkstra<int> d(G, s), d2(G, t);

  rep(u, n) {
    if (u == s || u == t) continue;
    if (!d.hasPathTo(u) || !d2.hasPathTo(u)) continue;
    if (d.distTo(u) == d2.distTo(u)) {
      cout << u + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
