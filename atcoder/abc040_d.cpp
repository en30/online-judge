#include <bits/stdc++.h>
#include "../include/template"
#include "../include/weighted_edge.hpp"
#include "../include/union_find_tree.hpp"

struct Query {
  int i, v, w, ans;
};
int main() {
  int N, M;
  cin >> N >> M;
  using Edge = WeightedEdge<int>;
  vector<Edge> E(M);
  rep(i, M) cin >> E[i];

  int Q;
  cin >> Q;
  vector<Query> qs(Q);
  rep(i, Q) {
    qs[i].i = i;
    cin >> qs[i].v >> qs[i].w;
    --qs[i].v;
  }

  UnionFindTree uf(N);
  sort(E.rbegin(), E.rend(),
       [](const Edge& a, const Edge& b) { return a.weight() < b.weight(); });
  sort(qs.rbegin(), qs.rend(),
       [](const Query& a, const Query& b) { return a.w < b.w; });

  int j = 0;
  rep(i, Q) {
    while (j < M && E[j].weight() > qs[i].w) {
      uf.unite(E[j].from, E[j].to);
      ++j;
    }
    qs[i].ans = uf.size(qs[i].v);
  }
  sort(all(qs), [](const Query& a, const Query& b) { return a.i < b.i; });
  rep(i, Q) cout << qs[i].ans << endl;

  return 0;
}
