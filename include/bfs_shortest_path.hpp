#pragma once
#include "./edge.hpp"
#include "./graph.hpp"

class BFSShortestPath {
  const int INF = numeric_limits<int>::max();
  vector<int> _distTo;
  vector<int> prev;

 public:
  BFSShortestPath(const Digraph<Edge>& G, int s)
      : _distTo(G.V(), INF), prev(G.V(), -1) {
    queue<int> q;
    q.push(s);
    _distTo[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (Edge& e : G[u]) {
        if (_distTo[e.to] != INF) continue;
        _distTo[e.to] = _distTo[u] + 1;
        prev[e.to] = u;
        q.push(e.to);
      }
    }
  }

  int distTo(int u) { return _distTo[u]; }

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