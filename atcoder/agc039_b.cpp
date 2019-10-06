#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> G;

int f(int i) {
  vector<int> d(N, N * N);
  d[i] = 1;
  queue<int> q;
  q.push(i);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : G[u]) {
      if (d[v] < d[u] - 1) return -1;
      if (d[v] == d[u] - 1 || d[v] == d[u] + 1) continue;
      if (d[v] == d[u]) return -1;
      assert(d[v] == N * N);
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  return *max_element(all(d));
}

int main() {
  cin >> N;
  G.resize(N);
  rep(i, N) rep(j, N) {
    char c;
    cin >> c;
    if (c == '1') {
      G[i].push_back(j);
    };
  }

  int ans = -1;
  rep(i, N) ans = max(ans, f(i));
  cout << ans << endl;

  return 0;
}
