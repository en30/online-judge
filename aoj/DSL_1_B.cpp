#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)

class UnionFindTree {
  struct edge {
    int node;
    int distance;
  };
  vector<edge> root;
  vector<int> rank;

  edge findRoot(int x) {
    if(x != root[x].node) {
      edge e = findRoot(root[x].node);
      root[x] = edge{e.node, e.distance + root[x].distance};
    }
    return root[x];
  }

public:

  UnionFindTree(int size) {
    rank = vector<int>(size, 0);
    root = vector<edge>(size, edge{});
    for(int i = 0; i < size; i++) root[i] = edge{i,0};
  }

  void relate(int x, int y, int z) {
    edge ex = findRoot(x);
    edge ey = findRoot(y);
    if(ex.node == ey.node)return;

    int d = z + ey.distance - ex.distance;
    if(rank[ex.node] < rank[ey.node]) {
      root[ex.node] = edge{ey.node, d};
    } else {
      root[ey.node] = edge{ex.node, -d};
      if(rank[ex.node] == rank[ey.node]) rank[ex.node]++;
    }
  }

  string difference(int x, int y) {
    edge ex = findRoot(x);
    edge ey = findRoot(y);
    if(ex.node == ey.node) {
      return to_string(ex.distance - ey.distance);
    } else {
      return "?";
    };
  }
};

int main () {
  int n, q;
  cin >> n >> q;
  UnionFindTree uft(n);

  rep(i,q) {
    int c, x, y, z;
    cin >> c;
    if(c == 0) {
      cin >> x >> y >> z;
      uft.relate(x, y, z);
      continue;
    }
    cin >> x >> y;
    cout << uft.difference(x, y) << endl;
  }

  return 0;
}
