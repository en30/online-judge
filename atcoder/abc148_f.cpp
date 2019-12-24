#include <bits/stdc++.h>
#include "../include/template"

class UndirectedGraph {
 public:
  int V, E;
  vector<vector<int>> adj;
  UndirectedGraph(int V) : V(V), E(0) { adj.resize(V); }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++E;
  }

  int deg(int u) { return adj[u].size(); }

  vector<int> singleSourceShortestPath(int s) {
    vector<int> d(V, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int w : adj[v]) {
        if (d[w] != -1) continue;
        d[w] = d[v] + 1;
        q.push(w);
      }
    }
    return d;
  }
};

int N, u, v, M;

int main() {
  cin >> N >> u >> v;
  --u, --v;

  UndirectedGraph g(N);

  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    g.addEdge(A, B);
  }

  vector<int> dT = g.singleSourceShortestPath(u),
              dA = g.singleSourceShortestPath(v);

  if (g.deg(u) == 1 && g.adj[u][0] == v) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;

  rep(i, N) {
    if (dT[i] < dA[i]) ans = max(ans, dA[i] - 1);
  }

  cout << ans << endl;

  return 0;
}
