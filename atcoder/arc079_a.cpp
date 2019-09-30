#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> G;

int main() {
  cin >> N >> M;
  G.resize(N);

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  auto ok = [&]() {
    for (int u : G[0]) {
      for (int v : G[u]) {
        if (v == N - 1) return true;
      }
    }
    return false;
  };

  cout << (ok() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
