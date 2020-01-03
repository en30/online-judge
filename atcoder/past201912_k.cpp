#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lca.hpp"

int N, Q;
vector<int> p;
vector<vector<int>> G;

int main() {
  cin >> N;
  p.resize(N);
  G.resize(N);

  int root;
  rep(i, N) {
    cin >> p[i];
    if (p[i] == -1) {
      root = i;
      continue;
    }
    --p[i];
    G[i].push_back(p[i]);
    G[p[i]].push_back(i);
  }

  LCA lca(G, root);

  cin >> Q;
  rep(i, Q) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (lca.find(a, b) == b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
