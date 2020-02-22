#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/graph.hpp"

int main() {
  int N, K, L;
  cin >> N >> K >> L;

  vector<int> gk(N, -1), gl(N, -1);
  Digraph<Edge> Gk(N), Gl(N);
  rep(i, K) {
    Edge e;
    cin >> e;
    Gk.addUndirectedEdge(e);
  }
  rep(i, L) {
    Edge e;
    cin >> e;
    Gl.addUndirectedEdge(e);
  }

  function<void(Digraph<Edge>&, vector<int>&, int, int)> dfs =
      [&](Digraph<Edge>& G, vector<int>& group, int u, int g) {
        group[u] = g;
        for (Edge& e : G[u]) {
          if (group[e.to] != -1) continue;
          dfs(G, group, e.to, g);
        }
      };

  rep(i, N) {
    if (gk[i] == -1) dfs(Gk, gk, i, i);
    if (gl[i] == -1) dfs(Gl, gl, i, i);
  }

  vector<pair<int, int>> sorted;
  rep(i, N) sorted.emplace_back(gk[i], gl[i]);
  sort(all(sorted));

  rep(i, N) {
    auto p = equal_range(all(sorted), make_pair(gk[i], gl[i]));
    if (i) cout << " ";
    cout << p.second - p.first;
  }
  cout << endl;

  return 0;
}
