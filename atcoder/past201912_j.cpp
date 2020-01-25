#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int H, W;
vector<vector<int>> A;

int main() {
  cin >> H >> W;

  A.resize(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];

  int V = H * W;
  EdgeWeightedDigraph<ll> G(V);

  auto index = [&](int i, int j) { return i * W + j; };

  auto connect = [&](int i, int j, int i2, int j2) {
    G.addEdge(index(i, j), index(i2, j2), A[i][j] + A[i2][j2]);
    G.addEdge(index(i2, j2), index(i, j), A[i][j] + A[i2][j2]);
  };

  rep(i, H) rep(j, W) {
    if (i + 1 < H) connect(i, j, i + 1, j);
    if (i - 1 >= 0) connect(i, j, i - 1, j);
    if (j + 1 < W) connect(i, j, i, j + 1);
    if (j - 1 >= 0) connect(i, j, i, j - 1);
  }

  Dijkstra<ll> d(G, index(H - 1, 0)), d2(G, index(H - 1, W - 1)),
      d3(G, index(0, W - 1));

  ll ans = 1e18;
  rep(i, H) rep(j, W) {
    ans = min(ans, d.distTo(index(i, j)) + d2.distTo(index(i, j)) +
                       d3.distTo(index(i, j)) - A[i][j]);
  }

  cout << ans / 2 << endl;
  return 0;
}
