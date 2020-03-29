#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lca.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, n - 1) {
    int u, v;
    scanf("%d %d\n", &u, &v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  LCA lca(G);

  auto query = [&]() {
    int k;
    scanf("%d", &k);

    vector<int> v(k);
    int maxD = 0, farthest = 0;
    rep(i, k) {
      scanf("%d", &v[i]);
      --v[i];
      if (chmax(maxD, lca.depth(v[i]))) farthest = v[i];
    }

    rep(i, k) {
      int u = lca.find(farthest, v[i]);
      if (lca.depth(v[i]) - lca.depth(u) > 1) {
        printf("NO\n");
        return;
      }
    }

    printf("YES\n");
  };

  rep(i, m) query();
  return 0;
}
