#include <bits/stdc++.h>
#include "../include/template"
class UnionFindTree {
  vector<int> parent, rank;

 public:
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  UnionFindTree(int size) {
    parent = vector<int>(size);
    rank = vector<int>(size, 0);
    for (int i = 0; i < size; i++) parent[i] = i;
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

int N, M;

int main() {
  cin >> N >> M;

  UnionFindTree t(N);

  rep(i, M) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    t.unite(x, y);
  }

  set<int> s;
  rep(i, N) s.insert(t.find(i));

  cout << s.size() << endl;
  return 0;
}
