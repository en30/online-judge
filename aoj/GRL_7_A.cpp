#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ford_fulkerson.hpp"

int main() {
  int X, Y, E;
  cin >> X >> Y >> E;

  // s, X, Y, t
  int s = 0;
  int t = 1 + X + Y;

  FordFulkerson G(t + 1);

  rep(i, X) G.addEdge(s, i + 1, 1);
  rep(i, Y) G.addEdge(1 + X + i, t, 1);
  rep(i, E) {
    int x, y;
    cin >> x >> y;
    G.addEdge(x + 1, 1 + X + y, FordFulkerson::INF);
  }

  cout << G.maxflow(s, t) << endl;

  return 0;
}
