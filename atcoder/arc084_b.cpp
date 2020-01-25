#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int K;

int main() {
  cin >> K;

  EdgeWeightedDigraph<int> G(K);
  rep(i, K) {
    G.addEdge(i, (i + 1) % K, 1);
    G.addEdge(i, (i * 10) % K, 0);
  }

  Dijkstra<int> d(G, 1);
  cout << d.distTo(0) + 1 << endl;

  return 0;
}
