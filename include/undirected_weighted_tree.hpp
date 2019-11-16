class UndirectedWeightedTree {
  struct Edge {
    int dest, weight;
  };
  struct Result {
    int dest, distance;
  };

  int _E, _V;
  vector<vector<Edge>> adjacentList;

 public:
  int E() { return _E; }

  int V() { return _V; }

  UndirectedWeightedTree(){};
  UndirectedWeightedTree(int V) : _V(V) { adjacentList.resize(V); }

  void addEdge(int u, int v, int w) {
    adjacentList[u].push_back(Edge{v, w});
    adjacentList[v].push_back(Edge{u, w});
    ++_E;
  }

  int diameter() {
    function<Result(int, int)> dfs = [&](int previous, int current) {
      Result r = {current, 0};
      for (Edge& e : adjacentList[current])
        if (e.dest != previous) {
          Result t = dfs(current, e.dest);
          t.distance += e.weight;
          if (r.distance < t.distance) r = t;
        }
      return r;
    };

    Result r = dfs(-1, 0);
    Result t = dfs(-1, r.dest);
    return t.distance;
  }

  void scanFrom(std::istream& strm) {
    strm >> _V;
    adjacentList.resize(_V);
    for (int i = 0; i < _V - 1; ++i) {
      int u, v, w;
      strm >> u >> v >> w;
      addEdge(u, v, w);
    }
    assert(_E == _V - 1);
  }
};

inline std::istream& operator>>(std::istream& strm, UndirectedWeightedTree& t) {
  t.scanFrom(strm);
  return strm;
}
