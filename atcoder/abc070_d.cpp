#include <bits/stdc++.h>
#include "../include/template"

const ll INF = numeric_limits<ll>::max() / 2;
struct edge {
  int to, cost;
};
struct node {
  int id, distance;
  node(int id, int distance) : id(id), distance(distance) {}
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
    for (edge e : G[n.id]) {
      if (distance[e.to] > distance[n.id] + e.cost) {
        distance[e.to] = distance[n.id] + e.cost;
        que.push(node(e.to, distance[e.to]));
      }
    }
  }
  return distance;
}

int N, K, Q;
vector<vector<edge>> G;

int main() {
  cin >> N;
  G.resize(N);
  rep(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(edge{b, c});
    G[b].push_back(edge{a, c});
  }

  cin >> Q >> K;
  K--;
  vector<ll> distance = dijkstra(G, K);

  rep(i, Q) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << distance[x] + distance[y] << endl;
  }
  return 0;
}
