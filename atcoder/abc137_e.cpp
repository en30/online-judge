#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, M, P;

const int INF = 1e9;
struct edge { int from, to, cost; };

vector<int> bellmanFord(int V, vector<edge> &edges, int source) {
  int E = edges.size();
  vector<int> distances(V, INF);

  distances[source] = 0;
  bool updated = true;
  int count = 0;
  while(updated) {
    updated = false;
    rep(i,E) {
      edge e = edges[i];
      if(distances[e.from] != INF && distances[e.to] > distances[e.from] + e.cost) {
        distances[e.to] = distances[e.from] + e.cost;
        updated = true;
      }
    }
    count++;
    if(updated && count == V) return vector<int>(); // negative cycle
  }
  return distances;
}


int main () {
  cin >> N >> M >> P;

  vector<edge> edges(M);
  rep(i,M) {
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    edges[i].from--, edges[i].to--;
    edges[i].cost = P - edges[i].cost;
  }

  vector<int> rf(N, 0), rb(N, 0);
  rf[0] = 1;
  rb[N-1] = 1;
  rep(i,N) rep(j,M) {
    if(rf[edges[j].from]) rf[edges[j].to] = 1;
    if(rb[edges[j].to]) rb[edges[j].from] = 1;
  }

  vector<edge> cleanEdges;
  rep(i,M) {
    if(!rf[edges[i].from] || !rf[edges[i].to] || !rb[edges[i].from] || !rb[edges[i].to]) continue;
    cleanEdges.push_back(edges[i]);
  }

  auto res = bellmanFord(N, cleanEdges, 0);

  if(res.empty()) {
    cout << -1 << endl;
  } else {
    cout << -min(res[N-1], 0) << endl;
  }

  return 0;
}
