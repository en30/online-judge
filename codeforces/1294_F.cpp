#include <bits/stdc++.h>
#include "../include/template"

vector<vector<int>> G;
vector<vector<pair<int, int>>> lpMemo, rpMemo;
vector<unordered_map<int, int>> id;

pair<int, int> depth(int, int);

// [0, pi)
pair<int, int> leftProduct(int u, int pi) {
  if (lpMemo[u][pi].first != -1) return lpMemo[u][pi];

  return lpMemo[u][pi] = max(depth(G[u][pi - 1], u), leftProduct(u, pi - 1));
}

// [pi, G[u].size())
pair<int, int> rightProduct(int u, int pi) {
  if (rpMemo[u][pi].first != -1) return rpMemo[u][pi];

  return rpMemo[u][pi] = max(depth(G[u][pi], u), rightProduct(u, pi + 1));
}

pair<int, int> depth(int u, int p) {
  auto d = max(leftProduct(u, id[u][p]), rightProduct(u, id[u][p] + 1));
  d.first += 1;
  return d;
};

int main() {
  int N;
  cin >> N;
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
    lpMemo[i].resize(G[i].size() + 1, make_pair(-1, -1));
    rpMemo[i].resize(G[i].size() + 1, make_pair(-1, -1));
    lpMemo[i][0] = make_pair(0, i);
    rpMemo[i][G[i].size()] = make_pair(0, i);
  }

  int d = 0;
  vector<pair<int, int>> s(3);
  rep(u, N) {
    if (G[u].size() < 2) continue;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, u));
    for (int v : G[u]) pq.push(depth(v, u));
    vector<pair<int, int>> curr(3);
    int cd = 0;
    rep(i, 3) {
      curr[i] = pq.top();
      cd += pq.top().first;
      pq.pop();
    }
    if (chmax(d, cd)) s = curr;
  }

  cout << d << endl;
  cout << (s[0].second + 1) << " " << (s[1].second + 1) << " "
       << (s[2].second + 1) << endl;

  return 0;
}
