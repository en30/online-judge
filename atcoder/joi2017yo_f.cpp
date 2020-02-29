#include <bits/stdc++.h>
#include "../include/template"
#include "../include/weighted_edge.hpp"
#include "../include/graph.hpp"

struct Node {
  int id, kind, left;
  ll distance;
  Node(int id, ll distance, int kind, int left)
      : id(id), distance(distance), kind(kind), left(left) {}
  bool operator<(const Node& theOther) const {
    return distance < theOther.distance;
  }
  bool operator>(const Node& theOther) const {
    return distance > theOther.distance;
  }
};

int main() {
  using Edge = WeightedEdge<int>;

  int N, M, X;
  cin >> N >> M >> X;
  vector<int> T(N);
  rep(i, N) cin >> T[i];

  Digraph<Edge> G(N);
  rep(i, M) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
  }

  const ll INF = 1e18;
  vector<vector<vector<ll>>> distTo(
      3, vector<vector<ll>>(X + 1, vector<ll>(N, INF)));
  distTo[0][X][0] = 0;

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push(Node(0, 0, 0, X));
  while (!pq.empty()) {
    Node n = pq.top();
    pq.pop();
    if (distTo[n.kind][n.left][n.id] < n.distance) continue;
    for (Edge& e : G[n.id]) {
      int nk = n.left == 0 ? T[n.id] : n.kind;
      int nl = max(0, (T[n.id] == 1 ? n.left : X) - e.weight());
      if (nl > 0 && (nk ^ T[e.to]) == 2) continue;
      if (distTo[nk][nl][e.to] > distTo[n.kind][n.left][n.id] + e.weight()) {
        distTo[nk][nl][e.to] = distTo[n.kind][n.left][n.id] + e.weight();
        pq.push(Node(e.to, distTo[nk][nl][e.to], nk, nl));
      }
    }
  }

  ll ans = INF;
  rep(i, 3) rep(j, X + 1) chmin(ans, distTo[i][j][N - 1]);
  cout << ans << endl;

  return 0;
}
