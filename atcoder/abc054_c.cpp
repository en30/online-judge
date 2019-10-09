#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> G;

int main() {
  cin >> N >> M;
  G.resize(N, vector<int>(N, 0));

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }

  vector<int> path(N - 1);
  rep(i, N - 1) path[i] = i + 1;

  int ans = 0;
  do {
    int u = 0;
    for (int v : path) {
      if (!G[u][v]) {
        --ans;
        break;
      }
      u = v;
    }
    ++ans;
  } while (next_permutation(path.begin(), path.end()));

  cout << ans << endl;

  return 0;
}
