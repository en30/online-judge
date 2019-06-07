#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

const int INF = 1e9;
const int MAX_V = 100;

struct edge { int to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];

void addEdge(int from, int to, int cap){
  G[from].push_back((edge) {to, cap, static_cast<int>(G[to].size())});
  G[to].push_back((edge) {from, 0, static_cast<int>(G[from].size()) - 1});
}

int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int maxFlow(int s, int t) {
  int flow = 0;
  while(true) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if( f == 0 ) return flow;
    flow += f;
  }
}

int main () {
  int V, E;
  cin >> V >> E;

  for(int i = 0; i < E; i++){
    int u, v, c;
    cin >> u >> v >> c;
    addEdge(u, v, c);
  }

  cout << maxFlow(0, V-1) << endl;
  return 0;
}
