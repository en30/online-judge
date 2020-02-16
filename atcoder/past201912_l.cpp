#include <bits/stdc++.h>
#include "../include/template"
#include "../include/prim.hpp"

int N, M;

struct Tower {
  int x, y, c;
};

vector<Tower> T, S;

int main() {
  using Edge = WeightedEdge<double>;

  cin >> N >> M;
  T.resize(N), S.resize(M);

  rep(i, N) cin >> T[i].x >> T[i].y >> T[i].c;
  rep(i, M) cin >> S[i].x >> S[i].y >> S[i].c;

  double ans = 1e20;
  Digraph<Edge> G(N);

  auto cost = [&](Tower &a, Tower &b) {
    double c = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (a.c != b.c) c *= 10;
    return c;
  };

  rep(i, N) rep(j, N) {
    if (i == j) continue;
    G.addEdge(Edge(i, j, cost(T[i], T[j])));
  }

  rep(s, (1 << M)) {
    Digraph<Edge> G2(G);
    vector<Tower> U(T);

    rep(i, M) if ((s >> i) & 1) {
      U.push_back(S[i]);
      G2.addNode();
      int u = G2.size() - 1;
      rep(j, G2.size() - 1) {
        double c = cost(U[u], U[j]);
        G2.addUndirectedEdge(Edge(u, j, c));
      }
    }
    ans = min(ans, Prim<double>(G2).weight());
  }

  cout << setprecision(7) << ans << endl;

  return 0;
}
