#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> G;

int dfs(int v, int p) {
  if (G[v].size() == 1 && G[v][0] == p) return 1;

  int l = 1e9, r = 0;
  for (int u : G[v]) {
    if (u == p) continue;
    int s = dfs(u, v);
    chmin(l, s);
    chmax(r, s);
  }
  return l + r + 1;
}

int main() {
  cin >> N;
  G.resize(N);
  rep(i, N - 1) {
    int B;
    cin >> B;
    --B;
    G[i + 1].push_back(B);
    G[B].push_back(i + 1);
  }

  cout << dfs(0, -1) << endl;
  return 0;
}
