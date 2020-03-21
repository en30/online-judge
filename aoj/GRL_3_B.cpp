#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bridge.hpp"

int main() {
  int V, E;
  cin >> V >> E;

  Digraph<IndexedEdge> G(V, E);

  for (int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    IndexedEdge e(s, t, i);
    G.addUndirectedEdge(e);
  }

  Bridge bridge(G);

  vector<IndexedEdge> edges;
  for (auto& e : bridge.edges()) {
    edges.push_back(e.from < e.to ? e : e.reverse());
  };
  sort(all(edges), [](const IndexedEdge& a, const IndexedEdge& b) {
    return a.from == b.from ? a.to < b.to : a.from < b.from;
  });
  for (const IndexedEdge& e : edges) {
    cout << e.from << " " << e.to << endl;
  }

  return 0;
}
