#include <bits/stdc++.h>
#include "../include/template"
#include "../include/floyd_warshall.hpp"

int N, M;

int main() {
  cin >> N >> M;

  vector<vector<int>> G(N, vector<int>(N, FloydWarshall<int>::INF));
  rep(i, M) {
    int a, b, t;
    cin >> a >> b >> t;
    --a, --b;
    G[a][b] = t;
    G[b][a] = t;
  }
  rep(i, N) G[i][i] = 0;

  FloydWarshall<int> f(G);

  int ans = FloydWarshall<int>::INF;
  rep(i, N) {
    int d = 0;
    rep(j, N) d = max(d, f.dist(i, j));
    ans = min(ans, d);
  }

  cout << ans << endl;

  return 0;
}
