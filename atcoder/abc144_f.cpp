#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> G;
vector<int> d;
vector<double> E, C;

double expectation(int u) {
  if (E[u] != -1) return E[u];

  double res = 0;
  rep(v, N) if (G[u][v]) res += expectation(v);
  res /= d[u];
  res += 1;
  return E[u] = res;
}

double coefficient(int v) {
  if (C[v] >= 0.0) return C[v];

  double res = 0.0;
  rep(u, N) if (G[u][v]) res += coefficient(u) / d[u];
  return C[v] = res;
}

int main() {
  cin >> N >> M;
  G.resize(N, vector<int>(N, 0));
  C.resize(N, -1.0);
  d.resize(N, 0);

  rep(i, M) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    G[s][t] = 1;
    ++d[s];
  }

  E.resize(N, -1);
  E[N - 1] = 0.0;
  expectation(0);

  C[0] = 1.0;
  coefficient(N - 1);

  double m = 0.0;
  rep(u, N) {
    if (d[u] == 1 && (C[u] - 1.0) < 1e-9) continue;
    rep(v, N) if (G[u][v]) {
      double deltaE = (d[u] == 1 ? -E[u] : (E[u] - E[v] - 1) / (d[u] - 1.0));
      m = min(m, C[u] * deltaE);
    }
  }

  printf("%.7lf\n", E[0] + m);

  return 0;
}
