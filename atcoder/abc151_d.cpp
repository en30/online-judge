#include <bits/stdc++.h>
#include "../include/template"
#include "../include/floyd_warshall.hpp"

int main() {
  int H, W;
  cin >> H >> W;

  int V = H * W;
  vector<vector<int>> G(V, vector<int>(V, FloydWarshall<int>::INF));

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  auto node = [&](int i, int j) { return i * W + j; };

  auto add = [&](int i, int j, int k, int l) {
    G[node(i, j)][node(k, l)] = 1;
    G[node(k, l)][node(i, j)] = 1;
  };

  rep(i, H) rep(j, W) {
    if (grid[i][j] == '#') continue;

    G[node(i, j)][node(i, j)] = 0;
    if (i - 1 >= 0 && grid[i - 1][j] != '#') add(i, j, i - 1, j);
    if (i + 1 < H && grid[i + 1][j] != '#') add(i, j, i + 1, j);
    if (j - 1 >= 0 && grid[i][j - 1] != '#') add(i, j, i, j - 1);
    if (j + 1 < W && grid[i][j + 1] != '#') add(i, j, i, j + 1);
  }

  FloydWarshall<int> fw(G);
  int ans = 0;
  rep(i, H) rep(j, W) rep(k, H) rep(l, W) {
    int u = node(i, j), v = node(k, l);
    int d = fw.dist(u, v);
    if (d == FloydWarshall<int>::INF) continue;
    ans = max(ans, d);
  }

  cout << ans << endl;

  return 0;
}
