#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"
#include "../include/bfs_shortest_path.hpp"

int solve(int H, int W) {
  int s = 0, t = W * H - 1;

  Grid<int> grid(H, W);
  Digraph<Edge> G(H * W);

  rep(i, H) {
    rep(j, W - 1) {
      int w;
      cin >> w;
      if (!w)
        G.addUndirectedEdge(
            Edge(grid.to1DIndex(i, j), grid.to1DIndex(i, j + 1)));
    }

    if (i == H - 1) break;

    rep(j, W) {
      int w;
      cin >> w;
      if (!w)
        G.addUndirectedEdge(
            Edge(grid.to1DIndex(i, j), grid.to1DIndex(i + 1, j)));
    }
  }

  BFSShortestPath sp(G, s);
  return sp.hasPathTo(t) ? sp.distTo(t) + 1 : 0;
}

int main() {
  int W, H;
  while (true) {
    cin >> W >> H;
    if (W == 0 && H == 0) break;
    cout << solve(H, W) << endl;
  }

  return 0;
}
