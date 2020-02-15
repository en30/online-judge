#pragma once

#include "./tree.hpp"

template <typename Edge>
class CentroidDecomposition {
  struct Centroid {
    int parent, subtreeSize;
    vector<int> children;
  };
  vector<Centroid> centroids;
  vector<int> sizeMemo;
  vector<bool> used;
  Tree<Edge> G;
  int root;

  int subtreeSize(int u, int p) {
    sizeMemo[u] = 1;
    for (Edge& e : G[u]) {
      if (e.to == p || used[e.to]) continue;
      sizeMemo[u] += subtreeSize(e.to, u);
    }
    return sizeMemo[u];
  }

  int moveToCentroid(int u, int p, int n) {
    for (Edge& e : G[u]) {
      if (e.to == p || used[e.to]) continue;
      if (sizeMemo[e.to] > n / 2) return moveToCentroid(e.to, u, n);
    }
    return u;
  }

  int findFirstCentroid(int s, int parentCentroid) {
    int n = subtreeSize(s, -1);
    int c = moveToCentroid(s, -1, n);
    centroids[c].subtreeSize = n;
    centroids[c].parent = parentCentroid;
    if (parentCentroid != -1) centroids[parentCentroid].children.push_back(c);
    return c;
  }

  int buildCentroidTree(int s, int parentCentroid) {
    int c = findFirstCentroid(s, parentCentroid);
    used[c] = true;
    for (Edge& e : G[c]) {
      if (used[e.to]) continue;
      buildCentroidTree(e.to, c);
    }
    used[c] = false;
    return c;
  }

 public:
  CentroidDecomposition(const Tree<Edge>& G) : G(G) {
    centroids.resize(G.V()), sizeMemo.resize(G.V()), used.resize(G.V(), false);
    root = buildCentroidTree(0, -1);
  }

  const Centroid& operator[](int i) { return centroids[i]; }

  int rootCentroid() { return root; }

  // TODO: implement a public method to divide and conquer
};