#include <bits/stdc++.h>
#include "../include/template"

int N, M;
vector<vector<int>> G;
vector<vector<ll>> lpMemo, rpMemo;
vector<unordered_map<int, int>> id;

int subtreeCount(int, int);

// [0, pi)
ll leftProduct(int u, int pi) {
  if (lpMemo[u][pi] != -1) return lpMemo[u][pi];

  return lpMemo[u][pi] =
             (subtreeCount(G[u][pi - 1], u) + 1) * leftProduct(u, pi - 1) % M;
}

// [pi, G[u].size())
ll rightProduct(int u, int pi) {
  if (rpMemo[u][pi] != -1) return rpMemo[u][pi];

  return rpMemo[u][pi] =
             (subtreeCount(G[u][pi], u) + 1) * rightProduct(u, pi + 1) % M;
}

int subtreeCount(int u, int p) {
  if (p == -1) return leftProduct(u, G[u].size());

  return leftProduct(u, id[u][p]) * rightProduct(u, id[u][p] + 1) % M;
}

int main() {
  cin >> N >> M;
  G.resize(N);
  id.resize(N);
  lpMemo.resize(N), rpMemo.resize(N);

  auto addEdge = [&](int u, int v) {
    id[u][v] = G[u].size();
    G[u].push_back(v);
  };

  rep(i, N - 1) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    addEdge(x, y);
    addEdge(y, x);
  }

  rep(i, N) {
    lpMemo[i].resize(G[i].size() + 1, -1);
    rpMemo[i].resize(G[i].size() + 1, -1);
    lpMemo[i][0] = 1;
    rpMemo[i][G[i].size()] = 1;
  }

  rep(i, N) cout << subtreeCount(i, -1) << endl;

  return 0;
}
