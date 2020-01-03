#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ford_fulkerson.hpp"

int N, G, E;

int main() {
  cin >> N >> G >> E;

  FordFulkerson g(N + 1);

  rep(i, G) {
    int p;
    cin >> p;
    g.addEdge(p, N, 1);
  }

  rep(i, E) {
    int a, b;
    cin >> a >> b;
    g.addEdge(a, b, 1);
    g.addEdge(b, a, 1);
  }

  cout << g.maxflow(0, N) << endl;

  return 0;
}
