#include <bits/stdc++.h>
#include "../include/template"

int N, M;

struct Tower {
  int x, y, c;
};

vector<Tower> T, S;

struct edge {
  int to;
  double cost;
};
struct node {
  int id;
  double distance;
  node(int id, double distance) : id(id), distance(distance) {}
  bool operator<(const node &theOther) const {
    return distance < theOther.distance;
  }
  bool operator>(const node &theOther) const {
    return distance > theOther.distance;
  }
};

double prim(vector<vector<edge>> &G) {
  double total = 0;
  int V = G.size();
  bool used[V];
  priority_queue<node, vector<node>, greater<node>> que;

  que.push(node(0, 0));
  for (int i = 0; i < V; i++) used[i] = false;

  while (!que.empty()) {
    node n = que.top();
    que.pop();
    if (used[n.id]) continue;
    used[n.id] = true;
    total += n.distance;
    for (edge e : G[n.id]) {
      if (!used[e.to]) que.push(node(e.to, e.cost));
    }
  }
  return total;
}

int main() {
  cin >> N >> M;
  T.resize(N), S.resize(M);

  rep(i, N) cin >> T[i].x >> T[i].y >> T[i].c;
  rep(i, M) cin >> S[i].x >> S[i].y >> S[i].c;

  double ans = 1e20;
  vector<vector<edge>> G(N);

  auto cost = [&](Tower &a, Tower &b) {
    double c = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (a.c != b.c) c *= 10;
    return c;
  };

  rep(i, N) rep(j, N) {
    if (i == j) continue;
    G[i].push_back(edge{j, cost(T[i], T[j])});
  }

  rep(s, (1 << M)) {
    vector<vector<edge>> G2(G);
    vector<Tower> U(T);

    rep(i, M) if ((s >> i) & 1) {
      U.push_back(S[i]);
      G2.push_back(vector<edge>());
      int u = G2.size() - 1;
      rep(j, G2.size() - 1) {
        double c = cost(U[u], U[j]);
        G2[u].push_back(edge{j, c});
        G2[j].push_back(edge{u, c});
      }
    }
    ans = min(ans, prim(G2));
  }

  cout << setprecision(7) << ans << endl;

  return 0;
}
