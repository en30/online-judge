#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/graph.hpp"
#include "../include/union_find_tree.hpp"

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  UnionFindTree uf(N);
  Digraph<Edge> GF(N), GB(N);
  rep(i, M) {
    Edge e;
    cin >> e;
    GF.addUndirectedEdge(e);
    uf.unite(e.from, e.to);
  }

  rep(i, K) {
    Edge e;
    cin >> e;
    GB.addUndirectedEdge(e);
  }

  rep(i, N) {
    if (i) cout << " ";
    int ans = uf.size(i) - 1;
    for (auto &e : GF[i]) ans -= uf.same(i, e.to);
    for (auto &e : GB[i]) ans -= uf.same(i, e.to);
    cout << ans;
  }
  cout << endl;

  return 0;
}
