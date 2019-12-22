#include <bits/stdc++.h>
#include "../include/template"

int N, u, v, M;
vector<vector<int>> G;

vector<int> bfs(int u) {
  vector<int> d(N, -1);
  queue<int> q;
  q.push(u);
  d[u] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int w : G[v]) {
      if (d[w] != -1) continue;
      d[w] = d[v] + 1;
      q.push(w);
    }
  }
  return d;
}

int main() {
  cin >> N >> u >> v;
  --u, --v;
  G.resize(N);

  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  vector<int> dT = bfs(u), dA = bfs(v);

  if (G[u].size() == 1 && G[u][0] == v) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;

  rep(i, N) {
    if (dT[i] < dA[i]) ans = max(ans, dA[i] - 1);
  }

  cout << ans << endl;

  return 0;
}
