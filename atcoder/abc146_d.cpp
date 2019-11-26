#include <bits/stdc++.h>
#include "../include/template"

int N;
int K;

struct Edge {
  int index, to;
};

vector<int> c;
vector<vector<Edge>> G;

void color(int u, int p, int pc) {
  int k = pc;
  for (Edge& e : G[u]) {
    if (e.to == p) continue;
    k = (k + 1) % K;
    c[e.index] = k;
    color(e.to, u, k);
  }
}

int main() {
  cin >> N;

  c.resize(N - 1, -1);
  G.resize(N);

  K = 0;

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(Edge{i, b});
    G[b].push_back(Edge{i, a});
  }

  rep(i, N) K = max(K, (int)G[i].size());

  color(0, -1, -1);

  cout << K << endl;
  rep(i, N - 1) cout << c[i] + 1 << endl;

  return 0;
}
