#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int K;

const int INF = 1e9;
struct edge { int to, cost; };
struct node {
  int id, distance;
  node(int id, int distance): id(id), distance(distance) {}
  bool operator <(const node &theOther) const { return distance < theOther.distance; }
  bool operator >(const node &theOther) const { return distance > theOther.distance; }
};

vector<int> dijkstra(vector<vector<edge> > &G, int source) {
  int V = G.size();
  vector<int> distance(V, INF);
  priority_queue<node, vector<node>, greater<node> > que;
  distance[source] = 0;
  que.push(node(source, 0));

  while(!que.empty()) {
    node n = que.top(); que.pop();
    if(distance[n.id] < n.distance) continue;
    for(edge e : G[n.id]) {
      if (distance[e.to] > distance[n.id] + e.cost) {
        distance[e.to] = distance[n.id] + e.cost;
        que.push(node(e.to, distance[e.to]));
      }
    }
  }
  return distance;
}

int main () {
  cin >> K;

  vector<vector<edge>> G(K);
  rep(i,K) {
    G[i].push_back(edge{(i+1) % K, 1});
    G[i].push_back(edge{(i*10) % K, 0});
  }

  auto res = dijkstra(G, 1);
  cout << res[0] + 1 << endl;

  return 0;
}
