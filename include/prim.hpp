#pragma once

#include "./weighted_edge.hpp"
#include "./graph.hpp"

template <typename T>
class Prim {
  struct Node {
    int id;
    T distance;
    Node(int id, T distance) {
      this->id = id;
      this->distance = distance;
    }
    bool operator<(const Node &theOther) const {
      return distance < theOther.distance;
    }
    bool operator>(const Node &theOther) const {
      return distance > theOther.distance;
    }
  };
  T _weight;

 public:
  Prim(const Digraph<WeightedEdge<T>> &G) {
    int total = 0;
    int V = G.size();
    bool used[V];
    priority_queue<Node, vector<Node>, greater<Node>> que;

    que.push(Node(0, 0));
    for (int i = 0; i < V; i++) used[i] = false;

    while (!que.empty()) {
      Node n = que.top();
      que.pop();
      if (used[n.id]) continue;
      used[n.id] = true;
      total += n.distance;
      for (WeightedEdge<T> &e : G[n.id]) {
        if (!used[e.to]) que.push(Node(e.to, e.weight()));
      }
    }
    _weight = total;
  }

  T weight() { return _weight; }
};
