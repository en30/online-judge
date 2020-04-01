#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ModInt::mod(998244353);

  int n;
  cin >> n;

  vector<vector<int>> G(n);

  rep(i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  enum NodeState {
    ISOLATED,
    NOT_INDEPENDENT_SET,
    INDEPENDENT_SET,
  };

  unordered_map<int, unordered_map<int, unordered_map<NodeState, ModInt>>> memo;
  function<ModInt(int, int, NodeState)> dfs = [&](int u, int p, NodeState s) {
    if (memo[p][u].find(s) != memo[p][u].end()) return memo[p][u][s];

    ModInt res = 1;
    for (int v : G[u]) {
      if (v == p) continue;
      ModInt c = 0;
      // use edge
      if (s == INDEPENDENT_SET) {
        c += dfs(v, u, NOT_INDEPENDENT_SET);
      } else if (s == NOT_INDEPENDENT_SET) {
        c += dfs(v, u, NOT_INDEPENDENT_SET) + dfs(v, u, INDEPENDENT_SET);
      }

      // do not use edge
      c += dfs(v, u, NOT_INDEPENDENT_SET) + dfs(v, u, INDEPENDENT_SET) -
           dfs(v, u, ISOLATED);
      res *= c;
    }
    return memo[p][u][s] = res;
  };

  cout << dfs(0, -1, NOT_INDEPENDENT_SET) + dfs(0, -1, INDEPENDENT_SET) -
              dfs(0, -1, ISOLATED) - 1
       << endl;

  return 0;
}
