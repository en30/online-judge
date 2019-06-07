#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)


struct edge {
  int u, v;
};

class UnionFindTree {
  vector<int> parent, rank, n;

  int find(int x) {
    if(parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

public:

  UnionFindTree(int size) {
    parent = vector<int>(size);
    rank = vector<int>(size, 0);
    n = vector<int>(size, 1);
    for(int i = 0; i < size; i++) parent[i] = i;
  }

  ll unite(int x, int y) {
    ll res = 0;
    x = find(x);
    y = find(y);
    if(x == y) return -1;

    res = n[x] * n[y];
    if(rank[x] < rank[y]) {
      parent[x] = y;
      n[y] += n[x];
    } else {
      parent[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
      n[x] += n[y];
    }
    return res;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int main () {
  ll N, M;
  cin >> N >> M;
  vector<edge> edges(M);
  rep(i,M) {
    cin >> edges[i].u >> edges[i].v;
  }
  UnionFindTree t = UnionFindTree(N + 1);

  vector<ll> ans(M+1);
  ans[M] = N*(N-1) / 2;
  for(int i = M - 1; i >= 0; i--) {
    ll d = 0;
    if(!t.same(edges[i].u, edges[i].v)) {
      d = t.unite(edges[i].u, edges[i].v);
    }
    ans[i] = ans[i+1] - d;
  }

  rep(i,M) {
    cout << ans[i+1] << endl;
  }
  return 0;
}
