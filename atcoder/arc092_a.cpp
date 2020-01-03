#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ford_fulkerson.hpp"

int N;
struct Point {
  int x, y;
};

vector<Point> r, b;

int main() {
  cin >> N;

  FordFulkerson G(2 * N + 2);
  r.resize(N), b.resize(N);
  rep(i, N) {
    cin >> r[i].x >> r[i].y;
    G.addEdge(0, i + 1, 1);
  }
  rep(i, N) {
    cin >> b[i].x >> b[i].y;
    G.addEdge(N + 1 + i, 2 * N + 1, 1);
  }

  rep(i, N) {
    rep(j, N) {
      if (r[i].x < b[j].x && r[i].y < b[j].y) {
        G.addEdge(i + 1, j + N + 1, FordFulkerson::INF);
      }
    }
  }

  cout << G.maxflow(0, 2 * N + 1) << endl;
  return 0;
}
