#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int main() {
  int N, K, Q;
  cin >> N;

  using Edge = WeightedEdge<ll>;
  Digraph<Edge> G(N, 2 * (N - 1));
  rep(i, N - 1) {
    Edge e;
    cin >> e;
    G.addEdge(e);
    G.addEdge(e.reverse());
  }

  cin >> Q >> K;
  K--;
  Dijkstra<ll> d(G, K);

  rep(i, Q) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << d.distTo(x) + d.distTo(y) << endl;
  }
  return 0;
}
