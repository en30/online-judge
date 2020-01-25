template <typename T>
struct WeightedEdge {
  int to;
  T weight;
  WeightedEdge(int to, T weight) : to(to), weight(weight) {}
};

template <typename T>
class EdgeWeightedDigraph {
  int _E, _V;
  vector<vector<WeightedEdge<T>>> _adjacencyList;

 public:
  int E() const { return _E; }

  int V() const { return _V; }
  int size() const { return _V; }

  EdgeWeightedDigraph() : _V(0), _E(0){};
  EdgeWeightedDigraph(int V, int E = 0) : _V(V), _E(E) {
    _adjacencyList.resize(V);
  }

  void addEdge(int u, int v, T w) {
    _adjacencyList[u].emplace_back(v, w);
    ++_E;
  }

  void scanFrom(std::istream& strm, int base = 1) {
    if (_V == 0) strm >> _V;
    if (_E == 0) strm >> _E;
    _adjacencyList.resize(_V);
    for (int i = 0; i < _E; ++i) {
      int u, v;
      T w;
      strm >> u >> v >> w;
      if (base == 1) --u, --v;
      assert(0 <= u < _V);
      assert(0 <= v < _V);
      addEdge(u, v, w);
    }
  }

  vector<WeightedEdge<T>> operator[](int u) const { return _adjacencyList[u]; }
  vector<vector<WeightedEdge<T>>>& adjacencyList() { return _adjacencyList; }
};

template <typename T>
inline std::istream& operator>>(std::istream& strm, EdgeWeightedDigraph<T>& t) {
  t.scanFrom(strm);
  return strm;
}

/**
 * @brief <a href="https://scrapbox.io/en30/Dijkstra%E6%B3%95">Dijkstra法</a>
 * O((E+V)logE)
 * @tparam T
 */
template <typename T>
class Dijkstra {
  const T INF = numeric_limits<T>::max() / 2;
  struct Node {
    int id;
    T distance;
    Node(int id, T distance) : id(id), distance(distance) {}
    bool operator<(const Node& theOther) const {
      return distance < theOther.distance;
    }
    bool operator>(const Node& theOther) const {
      return distance > theOther.distance;
    }
  };

  vector<T> _distTo;
  vector<int> prev;
  priority_queue<Node, vector<Node>, greater<Node>> pq;

 public:
  Dijkstra(const EdgeWeightedDigraph<T>& G, int source) {
    int V = G.V();
    for (int u = 0; u < V; ++u) {
      for (int i = 0; i < G[u].size(); ++i) {
        assert(G[u][i].weight >= 0);
      }
    }

    _distTo.resize(V, INF);
    prev.resize(V, -1);
    _distTo[source] = 0;
    pq.push(Node(source, 0));

    while (!pq.empty()) {
      Node n = pq.top();
      pq.pop();
      if (_distTo[n.id] < n.distance) continue;
      for (WeightedEdge<T>& e : G[n.id]) {
        if (_distTo[e.to] > _distTo[n.id] + e.weight) {
          _distTo[e.to] = _distTo[n.id] + e.weight;
          prev[e.to] = n.id;
          pq.push(Node(e.to, _distTo[e.to]));
        }
      }
    }
  }

  T distTo(int u) { return _distTo[u]; }

  bool hasPathTo(int u) { return _distTo[u] != INF; }

  vector<int> pathTo(int u) {
    assert(hasPathTo(u));
    vector<int> path;
    while (u != -1) {
      path.push_back(u);
      u = prev[u];
    }
    return path;
  }
};