#include <bits/stdc++.h>
#include "../include/template"
#include "../include/prim.hpp"

int main() {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> x(n);
  vector<pair<int, int>> y(n);

  rep(i, n) {
    int a, b;
    scanf("%d %d", &a, &b);
    x[i] = make_pair(a, i);
    y[i] = make_pair(b, i);
  }

  using Edge = WeightedEdge<int>;
  Digraph<Edge> G(n);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  rep(i, n - 1) {
    G.addUndirectedEdge(
        Edge(x[i].second, x[i + 1].second, x[i + 1].first - x[i].first));
    G.addUndirectedEdge(
        Edge(y[i].second, y[i + 1].second, y[i + 1].first - y[i].first));
  }

  printf("%d\n", Prim<int>(G).weight());
  return 0;
}
