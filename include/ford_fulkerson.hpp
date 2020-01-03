class FordFulkerson {
  struct Edge {
    int to, cap, rev;
  };

  int V;
  vector<bool> used;
  vector<vector<Edge>> G;

  int augmentFlow(int v, int t, int f) {
    if (v == t) return f;

    used[v] = true;
    for (Edge &e : G[v]) {
      if (!used[e.to] && e.cap > 0) {
        int d = augmentFlow(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

 public:
  const static int INF = numeric_limits<int>::max();
  FordFulkerson(int V) : V(V) { G = vector<vector<Edge>>(V); }

  void addEdge(int from, int to, int cap) {
    G[from].push_back(Edge{to, cap, static_cast<int>(G[to].size())});
    G[to].push_back(Edge{from, 0, static_cast<int>(G[from].size()) - 1});
  }

  // 最悪O(maxflow*|E|)
  int maxflow(int s, int t) {
    int flow = 0;
    while (true) {
      used = vector<bool>(V, false);
      int f = augmentFlow(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }

  bool inCut(int v) { return used[v]; }
};
