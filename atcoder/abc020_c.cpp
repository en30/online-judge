#include <bits/stdc++.h>
#include "../include/template"

ll x;

const ll INF = 1e18;

struct edge {
  int to;
  bool white;
  ll cost() { return white ? 1LL : x; };
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
      if (distance[e.to] > distance[n.id] + e.cost()) {
        distance[e.to] = distance[n.id] + e.cost();
        que.push(node(e.to, distance[e.to]));
      }
    }
  }
  return distance;
}

int main() {
  int H, W;
  ll T;
  cin >> H >> W >> T;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  int V = H * W;
  vector<vector<edge>> G(V);

  auto id = [&](int i, int j) { return i * W + j; };
  assert(id(0, 0) == 0);
  assert(id(H - 1, W - 1) == V - 1);

  auto addEdge = [&](int u, int v, bool white) {
    G[u].push_back(edge{v, white});
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
    if (dijkstra(G, s)[t] <= T) {
      l = x;
    } else {
      r = x;
    }
  }

  cout << l << endl;
  return 0;
}
