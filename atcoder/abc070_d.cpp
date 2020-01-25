#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int main() {
  int N, K, Q;
  cin >> N;

  EdgeWeightedDigraph G(N, 2 * (N - 1));
  cin >> G;

  cin >> Q >> K;
  K--;
  Dijkstra d(G, K);

  rep(i, Q) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << d.distTo(x) + d.distTo(y) << endl;
  }
  return 0;
}
