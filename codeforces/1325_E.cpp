#include <bits/stdc++.h>
#include "../include/template"
#include "../include/prime_table.hpp"
#include "../include/indexed_edge.hpp"
#include "../include/graph.hpp"

const int MAX_A = 1e6;
const int MAX_SQRT_A = 1e3;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);

  PrimeTable pt(MAX_A);

  map<int, int> primeIndex;
  int V = 1, E = 0;
  Digraph<IndexedEdge> G(1, 0);
  rep(i, n) {
    vector<int> ps;
    for (auto p : pt.factorize(a[i])) {
      if (p.second % 2 == 0) continue;
      if (primeIndex.find(p.first) == primeIndex.end()) {
        primeIndex[p.first] = V++;
        G.addNode();
      }
      ps.push_back(primeIndex[p.first]);
    };
    if (ps.size() == 0) {
      cout << 1 << endl;
      return 0;
    } else if (ps.size() == 1) {
      G.addUndirectedEdge(IndexedEdge(0, ps[0], E++));
    } else {
      G.addUndirectedEdge(IndexedEdge(ps[0], ps[1], E++));
    }
  }

  function<int(int)> shortestCycle = [&](int s) {
    vector<int> depth(V, -1);
    vector<bool> used(E, false);
    queue<int> q;
    q.emplace(s);
    depth[s] = 0;
    int res = INF;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& e : G[u]) {
        if (used[e.index]) continue;
        if (depth[e.to] != -1) {
          chmin(res, depth[u] + depth[e.to] + 1);
          continue;
        }

        q.emplace(e.to);
        used[e.index] = true;
        depth[e.to] = depth[u] + 1;
      }
    }
    return res;
  };

  int ans = shortestCycle(0);
  for (auto& p : primeIndex) {
    if (p.first > MAX_SQRT_A) continue;
    chmin(ans, shortestCycle(p.second));
  }
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
