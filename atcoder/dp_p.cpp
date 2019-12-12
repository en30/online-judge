#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N;
vector<vector<int>> G;
vector<vector<mint>> memo;

mint dfs(int u, int p, int c) {
  if (memo[u][c] != -1) return memo[u][c];

  mint res = 1;
  for (int v : G[u]) {
    if (v == p) continue;
    res *= (c == 0 ? dfs(v, u, 0) + dfs(v, u, 1) : dfs(v, u, 0));
  }
  return memo[u][c] = res;
}

int main() {
  cin >> N;
  G.resize(N);
  memo.resize(N, vector<mint>(2, -1));

  rep(i, N - 1) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  cout << dfs(0, -1, 0) + dfs(0, -1, 1) << endl;

  return 0;
}
