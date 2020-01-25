#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

ll x;

const ll INF = 1e18;

struct Edge {
  int from, to;
  bool white;
  ll weight() { return white ? 1LL : x; };
};

int main() {
  int H, W;
  ll T;
  cin >> H >> W >> T;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  int V = H * W;
  Digraph<Edge> G(V);

  auto id = [&](int i, int j) { return i * W + j; };
  assert(id(0, 0) == 0);
  assert(id(H - 1, W - 1) == V - 1);

  auto addEdge = [&](int u, int v, bool white) {
    G.addEdge(Edge{u, v, white});
  };

  int s, t;
  rep(i, H) rep(j, W) {
    if (grid[i][j] == 'S') s = id(i, j);
    if (grid[i][j] == 'G') t = id(i, j);
    if (i - 1 >= 0) addEdge(id(i, j), id(i - 1, j), grid[i - 1][j] != '#');
    if (i + 1 < H) addEdge(id(i, j), id(i + 1, j), grid[i + 1][j] != '#');
    if (j - 1 >= 0) addEdge(id(i, j), id(i, j - 1), grid[i][j - 1] != '#');
    if (j + 1 < W) addEdge(id(i, j), id(i, j + 1), grid[i][j + 1] != '#');
  }

  ll l = 1, r = 1e9;
  while (r - l > 1) {
    x = (l + r) / 2;
    Dijkstra<ll, Edge> d(G, s);
    if (d.distTo(t) <= T) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << l << endl;
  return 0;
}
