#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"

struct Edge {
  int to, id;
};

struct Question {
  vector<int> path;
  int g;
};

int main() {
  int N;
  cin >> N;
  vector<vector<Edge>> G(N);
  rep(i, N - 1) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    G[x].push_back(Edge{y, i});
    G[y].push_back(Edge{x, i});
  }

  vector<int> f(N - 1, 1);

  function<bool(int, int, int, Question&)> assignPath = [&](int u, int v, int p,
                                                            Question& q) {
    if (u == v) return true;

    for (Edge& e : G[u]) {
      if (e.to == p) continue;
      if (assignPath(e.to, v, u, q)) {
        q.path.push_back(e.id);
        return true;
      }
    }
    return false;
  };

  int m;
  cin >> m;
  vector<Question> Q(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b >> Q[i].g;
    --a, --b;
    assignPath(a, b, -1, Q[i]);
    for (int id : Q[i].path) chmax(f[id], Q[i].g);
  }

  rep(i, m) {
    int m = 1e9;
    for (int id : Q[i].path) chmin(m, f[id]);
    if (Q[i].g != m) {
      cout << -1 << endl;
      return 0;
    };
  }

  rep(i, N - 1) {
    if (i) cout << " ";
    cout << (f[i] == -1 ? 1 : f[i]);
  }
  cout << endl;

  return 0;
}
