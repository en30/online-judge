#include <bits/stdc++.h>
#include "../include/template"
#include "../include/weighted_edge.hpp"
#include "../include/centroid_decomposition.hpp"

int main() {
  int N, K;
  cin >> N >> K;

  using Edge = WeightedEdge<int>;
  Tree<Edge> G(N);
  rep(i, N - 1) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
  }

  CentroidDecomposition<Edge> cd(G);

  int ans = 0;
  vector<bool> used(N, false);

  function<void(int, int, int, vector<int> &)> enumeratePaths =
      [&](int v, int p, int d, vector<int> &ds) {
        ds.push_back(d);
        for (Edge &e : G[v]) {
          if (e.to == p || used[v]) continue;
          enumeratePaths(e.to, v, d + e.weight(), ds);
        }
      };

  auto countPairs = [&](vector<int> &ds) {
    int res = 0;
    sort(all(ds));
    int j = ds.size();
    for (int i = 0; i < ds.size(); ++i) {
      while (j > 0 && ds[i] + ds[j - 1] > K) --j;
      res += j - (j > i ? 1 : 0);
    }
    return res / 2;
  };

  function<void(int)> solveSubproblem = [&](int c) {
    used[c] = true;

    for (int nc : cd[c].children) solveSubproblem(nc);

    vector<int> ds;
    ds.push_back(0);

    for (Edge &e : G[c]) {
      if (used[e.to]) continue;

      vector<int> tds;
      enumeratePaths(e.to, c, e.weight(), tds);

      ans -= countPairs(tds);
      ds.insert(ds.end(), all(tds));
    }

    ans += countPairs(ds);
    used[c] = false;
  };

  solveSubproblem(cd.rootCentroid());
  cout << ans << endl;

  return 0;
}
