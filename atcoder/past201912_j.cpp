#include <bits/stdc++.h>
#include "../include/template"

const ll INF = 1e18;

struct edge {
  int to;
  ll cost;
};

struct node {
  int id;
  ll distance;
  node(int id, ll distance) : id(id), distance(distance) {}
  bool operator<(const node &theOther) const {
    return distance < theOther.distance;
  }
  bool operator>(const node &theOther) const {
    return distance > theOther.distance;
  }
};

vector<ll> dijkstra(vector<vector<edge>> &G, int source) {
  int V = G.size();
  vector<ll> distance(V, INF);
  priority_queue<node, vector<node>, greater<node>> que;
  distance[source] = 0;
  que.push(node(source, 0));

  while (!que.empty()) {
    node n = que.top();
    que.pop();
    if (distance[n.id] < n.distance) continue;
    for (edge &e : G[n.id]) {
      if (distance[e.to] > distance[n.id] + e.cost) {
        distance[e.to] = distance[n.id] + e.cost;
        que.push(node(e.to, distance[e.to]));
      }
    }
  }
  return distance;
}

int H, W;
vector<vector<int>> A;

int main() {
  cin >> H >> W;

  A.resize(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];

  int V = H * W;
  vector<vector<edge>> G(V);

  auto index = [&](int i, int j) { return i * W + j; };

  auto connect = [&](int i, int j, int i2, int j2) {
    G[index(i, j)].push_back(edge{index(i2, j2), A[i][j] + A[i2][j2]});
    G[index(i2, j2)].push_back(edge{index(i, j), A[i][j] + A[i2][j2]});
  };

  rep(i, H) rep(j, W) {
    if (i + 1 < H) connect(i, j, i + 1, j);
    if (i - 1 >= 0) connect(i, j, i - 1, j);
    if (j + 1 < W) connect(i, j, i, j + 1);
    if (j - 1 >= 0) connect(i, j, i, j - 1);
  }

  vector<ll> d = dijkstra(G, index(H - 1, 0));
  vector<ll> d2 = dijkstra(G, index(H - 1, W - 1));
  vector<ll> d3 = dijkstra(G, index(0, W - 1));

  ll ans = 1e18;
  rep(i, H) rep(j, W) {
    ans =
        min(ans, d[index(i, j)] + d2[index(i, j)] + d3[index(i, j)] - A[i][j]);
  }

  cout << ans / 2 << endl;
  return 0;
}
