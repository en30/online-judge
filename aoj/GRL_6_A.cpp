#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ford_fulkerson.hpp"

int main() {
  int V, E;
  cin >> V >> E;

  FordFulkerson G(V);

  for (int i = 0; i < E; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    G.addEdge(u, v, c);
  }

  cout << G.maxflow(0, V - 1) << endl;
  return 0;
}
