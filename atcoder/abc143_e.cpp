#include <bits/stdc++.h>
#include "../include/template"

const int INF = 1e9 + 1;

int N, M, L, Q;
vector<vector<int>> d, b;
int main() {
  cin >> N >> M >> L;
  d.resize(N, vector<int>(N, INF));
  b.resize(N, vector<int>(N, INF));

  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--, B--;
    if (C > L) continue;
    d[A][B] = C;
    d[B][A] = C;
  }

  rep(i, N) d[i][i] = 0;

  rep(k, N) rep(i, N) rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  rep(i, N) rep(j, N) {
    if (d[i][j] <= L) b[i][j] = 1;
  }
  rep(i, N) b[i][i] = 0;

  rep(k, N) rep(i, N) rep(j, N) b[i][j] = min(b[i][j], b[i][k] + b[k][j]);

  cin >> Q;
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << (b[s][t] == INF ? -1 : b[s][t] - 1) << endl;
  }
  return 0;
}
