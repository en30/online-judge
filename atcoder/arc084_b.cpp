#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int K;

int main() {
  cin >> K;

  using Edge = WeightedEdge<int>;
  Digraph<Edge> G(K);
  rep(i, K) {
    G.addEdge(Edge(i, (i + 1) % K, 1));
    G.addEdge(Edge(i, (i * 10) % K, 0));
  }

  Dijkstra<int> d(G, 1);
  cout << d.distTo(0) + 1 << endl;

  return 0;
}
