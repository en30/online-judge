template <typename T>
struct WeightedEdge {
  int from, to;
  T _weight;
  WeightedEdge(){};
  WeightedEdge(int from, int to, T weight)
      : from(from), to(to), _weight(weight) {}

  void scanFrom(std::istream& strm, int base = 1) {
    strm >> from >> to >> _weight;
    if (base == 1) --from, --to;
  }

  T weight() { return _weight; }

  WeightedEdge reverse() { return WeightedEdge(to, from, _weight); }
};

template <typename T>
inline std::istream& operator>>(std::istream& strm, WeightedEdge<T>& t) {
  t.scanFrom(strm);
  return strm;
}

template <typename Edge>
class Digraph {
  int _E, _V;
  vector<vector<Edge>> _adjacencyList;

 public:
  int E() const { return _E; }

  int V() const { return _V; }
  int size() const { return _V; }

  Digraph() : _V(0), _E(0){};
  Digraph(int V, int E = 0) : _V(V), _E(E) { _adjacencyList.resize(V); }

  void addEdge(const Edge& e) {
    _adjacencyList[e.from].push_back(e);
    ++_E;
  }

  void scanFrom(std::istream& strm, int base = 1) {
    if (_V == 0) strm >> _V;
    if (_E == 0) strm >> _E;
    _adjacencyList.resize(_V);
    for (int i = 0; i < _E; ++i) {
      Edge e;
      e.scanFrom(cin, base);
      assert(0 <= e.from < _V);
      assert(0 <= e.to < _V);
      addEdge(e);
    }
  }

  vector<Edge> operator[](int u) const { return _adjacencyList[u]; }
  vector<vector<Edge>>& adjacencyList() { return _adjacencyList; }
};

template <typename Edge>
inline std::istream& operator>>(std::istream& strm, Digraph<Edge>& t) {
  t.scanFrom(strm);
  return strm;
}

/**
 * @brief <a href="https://scrapbox.io/en30/Dijkstra%E6%B3%95">Dijkstra法</a>
 * O((E+V)logE)
 * @tparam T
 */
template <typename T, typename Edge = WeightedEdge<T>>
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
  Dijkstra(const Digraph<Edge>& G, int source) {
    int V = G.V();
    for (int u = 0; u < V; ++u) {
      for (int i = 0; i < G[u].size(); ++i) {
        assert(G[u][i].weight() >= 0);
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
      for (Edge& e : G[n.id]) {
        if (_distTo[e.to] > _distTo[n.id] + e.weight()) {
          _distTo[e.to] = _distTo[n.id] + e.weight();
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
