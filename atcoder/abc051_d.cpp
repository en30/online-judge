#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int main() {
  int N, M;
  cin >> N >> M;
  using Edge = WeightedEdge<int>;
  Digraph<Edge> G(N);
  rep(i, M) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
  }

  set<pair<int, int>> used;

  rep(i, N) {
    Dijkstra<int> d(G, i);
    for (int j = i + 1; j < N; ++j) {
      if (!d.hasPathTo(j)) continue;
      auto path = d.pathTo(j);
      rep(k, int(path.size()) - 1) {
        used.insert(
            make_pair(min(path[k], path[k + 1]), max(path[k], path[k + 1])));
      }
    }
  }

  cout << M - used.size() << endl;

  return 0;
}
