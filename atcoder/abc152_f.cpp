#include <bits/stdc++.h>
#include "../include/template"

using EdgeSet = bitset<50>;

int N;

struct Edge {
  int to, id;
  Edge(int to, int id): to(to), id(id) {}
};

vector<vector<Edge>> G;

int main() {
  cin >> N;
  G.resize(N);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  int M;
  cin >> M;

  vector<EdgeSet> edges(M);

  function<bool(int, int,int,int)> dfs = [&](int c, int v, int tv, int p) {
    if(v == tv) return true;
    for(Edge& e: G[v]) {
      if(e.to == p) continue;
      if(dfs(c, e.to, tv, v)) {
        edges[c].set(e.id);
        return true;
      }
    }
    return false;
  };

  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    dfs(i, u, v, -1);
  }

  ll ans = 0;
  rep(subset,1<<M) {
    bitset<50> shouldWhite;
    rep(c,M) {
      if ((subset >> c) & 1) shouldWhite |= edges[c];
    }
    ll m = 1LL << (N - 1 - shouldWhite.count());
    if(__builtin_popcountll(subset) % 2 == 0) ans += m;
    else ans -= m;
  }

  cout << ans << endl;
  return 0;
}
