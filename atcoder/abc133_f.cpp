#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lca.hpp"

struct query {
  int x, y, u, v, lca;
};

class ColorfulTree {
  struct edge {
    int dest, color, distance;
  };

  vector<vector<edge>> G;
  vector<vector<int>> adj;
  vector<set<int>> relevantColor;

  vector<int> monochroDistance;
  map<int, map<int, int>> colorDistance;
  map<int, map<int, int>> colorNum;

  int V;
  int E;

  void dfs(int u, int parent, vector<int> &tmpColorDist,
           vector<int> &tmpColorNum) {
    for (int c : relevantColor[u]) {
      colorDistance[c][u] = tmpColorDist[c];
      colorNum[c][u] = tmpColorNum[c];
    }

    for (auto &e : G[u]) {
      if (e.dest != parent) {
        tmpColorDist[e.color] += e.distance;
        tmpColorNum[e.color]++;
        monochroDistance[e.dest] = monochroDistance[u] + e.distance;

        dfs(e.dest, u, tmpColorDist, tmpColorNum);
        tmpColorDist[e.color] -= e.distance;
        tmpColorNum[e.color]--;
      }
    }
  }

  int distanceBetweenNodes(auto &d, query &q) {
    return d[q.u] + d[q.v] - 2 * d[q.lca];
  };

 public:
  ColorfulTree(int _V) {
    V = _V;
    E = V - 1;
    G.resize(V);
    adj.resize(V);
    relevantColor.resize(V);
  }

  void addEdge(int u, int v, int color, int distance) {
    G[u].push_back(edge{v, color, distance});
    G[v].push_back(edge{u, color, distance});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> &adjacencyList() { return adj; }

  void relevant(int color, int u) { relevantColor[u].insert(color); }

  void collectDistances() {
    monochroDistance.resize(V);
    vector<int> tmpColorDist(E, 0);
    vector<int> tmpColorNum(E, 0);
    dfs(0, -1, tmpColorDist, tmpColorNum);
  }

  int process(query &q) {
    int d = distanceBetweenNodes(monochroDistance, q);
    int cd = distanceBetweenNodes(colorDistance[q.x], q);
    int n = distanceBetweenNodes(colorNum[q.x], q);
    return d - cd + n * q.y;
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;

  ColorfulTree t(N);

  rep(i, N - 1) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    t.addEdge(a, b, c, d);
  }

  auto G = t.adjacencyList();
  LCA lca(G);

  vector<query> queries(Q);
  rep(i, Q) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    x--;
    u--;
    v--;
    int l = lca.find(u, v);
    queries[i] = query{x, y, u, v, l};
    t.relevant(x, u);
    t.relevant(x, v);
    t.relevant(x, l);
  }

  t.collectDistances();

  for (auto &q : queries) {
    cout << t.process(q) << endl;
  }

  return 0;
}
