class UndirectedTree {
  int _E, _V;
  vector<vector<int>> _adjacencyList;

 public:
  int E() { return _E; }

  int V() { return _V; }

  UndirectedTree() : _V(0), _E(0){};
  UndirectedTree(int V) : _V(V), _E(0) { _adjacencyList.resize(V); }

  void addEdge(int u, int v) {
    _adjacencyList[u].push_back(v);
    _adjacencyList[v].push_back(u);
    ++_E;
  }

  void scanFrom(std::istream& strm, int base = 0) {
    strm >> _V;
    _adjacencyList.resize(_V);
    for (int i = 0; i < _V - 1; ++i) {
      int u, v;
      strm >> u >> v;
      if (base == 1) --u, --v;
      addEdge(u, v);
    }
    assert(_E == _V - 1);
  }

  vector<vector<int>>& adjacencyList() { return _adjacencyList; }
};

inline std::istream& operator>>(std::istream& strm, UndirectedTree& t) {
  t.scanFrom(strm);
  return strm;
}
