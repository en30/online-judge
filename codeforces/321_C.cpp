#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/centroid_decomposition.hpp"

int main() {
  int N;
  cin >> N;

  Tree<Edge> G(N);
  rep(i, N - 1) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
  }

  CentroidDecomposition<Edge> cd(G);
  vector<int> rank(N);

  function<void(int, int)> dfs = [&](int c, int r) {
    rank[c] = r;
    for (int nc : cd[c].children) dfs(nc, r + 1);
  };
  dfs(cd.rootCentroid(), 0);

  rep(i, N) if (rank[i] + 'A' > 'Z') {
    cout << "Impossible!" << endl;
    return 0;
  }

  rep(i, N) {
    if (i) cout << " ";
    cout << char(rank[i] + 'A');
  }
  cout << endl;

  return 0;
}
