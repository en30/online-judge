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

int N, M;
vector<int> p;

int main () {
  cin >> N >> M;
  p.resize(N);
  rep(i,N) {
    cin >> p[i];
    p[i]--;
  }

  auto t = new UnionFindTree(N);
  rep(i,M) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    t->unite(x, y);
  }

  int ans = 0;
  rep(i,N) {
    ans += t->same(i, p[i]);
  }
  cout << ans << endl;
  return 0;
}
