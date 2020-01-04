template <typename T>
class FloydWarshall {
  bool _hasNegativeCycle;
  vector<vector<T>> distTo;

 public:
  const static T INF = numeric_limits<T>::max() / 2;
  FloydWarshall(vector<vector<T>> G) {
    int V = G.size();

    distTo.resize(V, vector<T>(V, INF));

    for (int u = 0; u < V; ++u) {
      for (int v = 0; v < V; ++v) {
        if (u == v) {
          distTo[u][v] = 0;
          continue;
        }

        distTo[u][v] = G[u][v];
      }
    }

    for (int w = 0; w < V; ++w) {
      for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
          distTo[u][v] = min(distTo[u][v], distTo[u][w] + distTo[w][v]);
        }

        if (distTo[u][u] < 0) {
          _hasNegativeCycle = true;
          return;
        }
      }
    }
  }

  bool hasNegativeCycle() { return _hasNegativeCycle; }

  T dist(int s, int t) { return distTo[s][t]; }
};
