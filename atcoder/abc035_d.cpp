#include <bits/stdc++.h>
#include "../include/template"
#include "../include/dijkstra.hpp"

int main() {
  int N, M, T;
  cin >> N >> M >> T;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  using Edge = WeightedEdge<ll>;
  Digraph<Edge> G(N), RG(N);
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    G.addEdge(Edge(a, b, c));
    RG.addEdge(Edge(b, a, c));
  }

  Dijkstra<ll> d(G, 0), rd(RG, 0);

  ll ans = 0;
  rep(i, N) {
    if (d.hasPathTo(i) && rd.hasPathTo(i)) {
      chmax(ans, (T - d.distTo(i) - rd.distTo(i)) * A[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
