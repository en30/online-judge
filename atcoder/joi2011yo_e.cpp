#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"
#include "../include/bfs_shortest_path.hpp"

struct Position {
  int y, x;
};

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  Grid<char> grid(H, W);
  cin >> grid;

  vector<Position> P(N + 1);
  Digraph<Edge> G(H * W);
  rep(i, H) rep(j, W) {
    if (grid[i][j] != 'X' && grid[i][j] != '.') {
      P[grid[i][j] == 'S' ? 0 : (grid[i][j] - '0')] = Position{i, j};
    }
    int u = grid.to1DIndex(i, j);
    for (auto& p : grid.neighbor4(i, j)) {
      if (grid[p.i][p.j] == 'X') continue;
      G.addEdge(Edge(u, grid.to1DIndex(p.i, p.j)));
    }
  }

  int ans = 0;
  rep(i, N) {
    BFSShortestPath sp(G, grid.to1DIndex(P[i].y, P[i].x));
    ans += sp.distTo(grid.to1DIndex(P[i + 1].y, P[i + 1].x));
  }
  cout << ans << endl;

  return 0;
}
