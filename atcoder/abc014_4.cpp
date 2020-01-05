#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"
#include "../include/lca.hpp"

int N, Q;

int main() {
  UndirectedTree G;
  G.scanFrom(cin, 1);
  LCA lca(G.adjacencyList());
  cin >> Q;
  rep(i, Q) {
    int a, b;
    cin >> a >> b;
    --a, --b;

    int c = lca.find(a, b);
    cout << lca.depth(a) + lca.depth(b) - 2 * lca.depth(c) + 1 << endl;
  }

  return 0;
}
