#include <bits/stdc++.h>
#include "../include/template"
#include "../include/floyd_warshall.hpp"

int main() {
  int N, M;
  cin >> N >> M;

  const int INF = FloydWarshall<int>::INF;
  vector<pair<int, int>> neighbor;
  vector<vector<int>> G(N, vector<int>(N, INF));
  rep(i, M) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    if (v == 0) swap(u, v);
    if (u == 0) {
      neighbor.emplace_back(v, w);
    } else {
      G[u][v] = w;
      G[v][u] = w;
    }
  }

  FloydWarshall<int> fw(G);
  int K = neighbor.size();
  int ans = INF;
  rep(i, K) for (int j = i + 1; j < K; ++j) {
    int d = fw.dist(neighbor[i].first, neighbor[j].first);
    if (d == INF) continue;
    chmin(ans, neighbor[i].second + neighbor[j].second + d);
    ;
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
