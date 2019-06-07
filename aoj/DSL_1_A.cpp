#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class UnionFindTree {
  vector<int> parent, rank;

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
    for(int i = 0; i < size; i++) parent[i] = i;
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)return;

    if(rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};


int main () {
  int n, q;

  cin >> n >> q;

  UnionFindTree uft(n);
  for(int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if(c == 0) {
      uft.unite(x, y);
      continue;
    }
    cout << uft.same(x, y) << endl;
  }

  return 0;
}
