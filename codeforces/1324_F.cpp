#include <bits/stdc++.h>
#include "../include/template"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);

  vector<vector<int>> G(n);
  gp_hash_table<int, gp_hash_table<int, int>> memo;
  const int UNINITIALIZED = 1e9;
  rep(i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
    memo[u][v] = UNINITIALIZED;
    memo[v][u] = UNINITIALIZED;
  }
  rep(i, n) memo[-1][i] = UNINITIALIZED;

  function<int(int, int, int)> dfs = [&](int u, int p, int f) {
    if (memo[p][u] != UNINITIALIZED) return memo[p][u];

    int res = 0;
    if (f || p == -1) {
      res = 2 * a[u] - 1;
      for (int v : G[u]) {
        if (v == p) continue;
        res += max(0, dfs(v, u, f));
      }
    } else {
      res += dfs(u, -1, f) - max(0, dfs(p, u, f));
    }
    return memo[p][u] = res;
  };

  dfs(0, -1, 1);
  rep(i, n) {
    if (i) cout << " ";
    printf("%d", dfs(i, -1, 0));
  }
  cout << endl;

  return 0;
}
