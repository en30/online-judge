#pragma once

#include "./indexed_edge.hpp"
#include "./graph.hpp"

class Bridge {
  vector<int> depth, passingBackEdgeCount;
  vector<IndexedEdge> bridges;

  int dfs(int u, int p, int d, const Digraph<IndexedEdge>& G) {
    depth[u] = d;
    int up = 0, down = 0, prefixSum = 0;
    for (IndexedEdge& e : G[u]) {
      if (depth[e.to] != -1) {
        if (depth[e.to] < depth[u] - 1) ++up;
        if (depth[e.to] > depth[u] + 1) ++down;
        continue;
      }
      prefixSum += dfs(e.to, u, d + 1, G);
    }
    return passingBackEdgeCount[u] = up - down + prefixSum;
  }

 public:
  Bridge(const Digraph<IndexedEdge>& G) {
    const int V = G.V();
    depth.resize(V, -1);
    passingBackEdgeCount.resize(V, 0);

    rep(u, V) if (depth[u] == -1) dfs(u, -1, 0, G);
    rep(u, V) {
      if (passingBackEdgeCount[u] != 0) continue;

      for (IndexedEdge& e : G[u]) {
        if (depth[e.to] + 1 != depth[u]) continue;
        bridges.push_back(e);
      }
    }
  }

  vector<IndexedEdge> edges() { return bridges; }
};
