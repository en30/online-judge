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
