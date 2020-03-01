#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"
#include "../include/bfs_shortest_path.hpp"

int main() {
  int R, C;
  int sy, sx, gy, gx;

  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;
  --sy, --sx, --gy, --gx;

  Grid<char> grid(R, C);
  cin >> grid;

  Digraph<Edge> G(R * C);
  rep(i, R) rep(j, C) {
    int u = grid.to1DIndex(i, j);
    for (auto& p : grid.neighbor4(i, j)) {
      if (grid[p.i][p.j] == '#') continue;
      G.addEdge(Edge(u, grid.to1DIndex(p.i, p.j)));
    }
  }

  BFSShortestPath sp(G, grid.to1DIndex(sy, sx));
  cout << sp.distTo(grid.to1DIndex(gy, gx)) << endl;

  return 0;
}
