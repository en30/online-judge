#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> G;

int dfs(int v) {
  if (G[v].size() == 0) return 1;

  int l = 1e9, r = 0;
  for (int u : G[v]) {
    int s = dfs(u);
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
    G[B].push_back(i + 1);
  }

  cout << dfs(0) << endl;
  return 0;
}
