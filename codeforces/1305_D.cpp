#include <bits/stdc++.h>
#include "../include/template"
#include "../include/edge.hpp"
#include "../include/tree.hpp"

int query(int u, int v) {
  cout << "? " << u + 1 << " " << v + 1 << endl;
  int w;
  cin >> w;
  if (w == -1) exit(0);
  return w - 1;
}

int main() {
  int n;
  cin >> n;

  Tree<Edge> G(n);
  vector<int> deg(n, 0);
  rep(i, n - 1) {
    Edge e;
    cin >> e;
    G.addUndirectedEdge(e);
    ++deg[e.from];
    ++deg[e.to];
  }

  vector<bool> used(n, false);
  function<void(int, int)> removeSubtree = [&](int u, int p) {
    used[u] = true;
    for (auto& e : G[u]) {
      if (used[e.to] || e.to == p) continue;
      --deg[u];
      --deg[e.to];
      removeSubtree(e.to, u);
    }
  };

  int ans;
  while (true) {
    int u = -1, v = -1;
    rep(i, n) if (!used[i] && deg[i] == 1) {
      u = i;
      break;
    }
    for (int i = u + 1; i < n; ++i) {
      if (!used[i] && deg[i] == 1) {
        v = i;
        break;
      }
    }
    if (u == -1 && v == -1) {
      rep(i, n) if (!used[i]) ans = i;
      break;
    }
    int w = query(u, v);
    if (w == u || w == v) {
      ans = w;
      break;
    }
    used[w] = true;
    removeSubtree(u, -1);
    removeSubtree(v, -1);
    deg[w] -= 2;
    used[w] = false;
  }

  cout << "! " << ans + 1 << endl;

  return 0;
}
