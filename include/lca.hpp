class LCA {
  vector<vector<int>> parent;
  vector<int> depth;
  int logV;

  void dfs(int u, int p, int d, vector<vector<int>> &adjacencyList) {
    parent[0][u] = p;
    depth[u] = d;
    for (auto v : adjacencyList[u]) {
      if (v != p) dfs(v, u, d + 1, adjacencyList);
    }
  }

 public:
  LCA(vector<vector<int>> &adjacencyList, int root = 0) {
    int V = adjacencyList.size();
    logV = 0;
    while ((1 << logV) < V) logV++;
    parent.resize(logV, vector<int>(V));
    depth.resize(V);

    dfs(root, -1, 0, adjacencyList);
    for (int k = 0; k + 1 < logV; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  int find(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logV; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;
    for (int k = logV - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
