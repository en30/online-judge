#pragma once

template <typename Edge>
class Tree {
  int _E, _V;
  vector<vector<Edge>> _adjacencyList;

 public:
  int E() const { return _E; }

  int V() const { return _V; }
  int size() const { return _V; }

  Tree() : _V(0), _E(0){};
  Tree(int V) : _V(V), _E(0) { _adjacencyList.resize(V); }

  void addEdge(const Edge& e) {
    _adjacencyList[e.from].push_back(e);
    ++_E;
  }

  void addUndirectedEdge(const Edge& e) {
    _adjacencyList[e.from].push_back(e);
    _adjacencyList[e.to].push_back(e.reverse());
    ++_E;
  }

  void scanFrom(std::istream& strm, int base = 1) {
    if (_V == 0) strm >> _V;
    _adjacencyList.resize(_V);
    for (int i = 0; i < _V - 1; ++i) {
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
inline std::istream& operator>>(std::istream& strm, Tree<Edge>& t) {
  t.scanFrom(strm);
  return strm;
}
