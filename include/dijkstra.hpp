#pragma once
#include "./weighted_edge.hpp"
#include "./graph.hpp"

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
