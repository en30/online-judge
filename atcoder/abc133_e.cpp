#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

int N, K;
vector<vector<int>> G;
vector<int> visited;

mint dfs(int u, int n1, int n2) {
  visited[u] = 1;
  mint res = K - n1 - n2;
  for (int v : G[u]) {
    if (visited[v]) continue;
    res *= dfs(v, 1, n1);
    n1++;
  }
  return res;
}

int main() {
  cin >> N >> K;

  G.resize(N);
  visited.resize(N, 0);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << dfs(0, 0, 0) << endl;
  return 0;
}
