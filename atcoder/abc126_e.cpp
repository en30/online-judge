#include <bits/stdc++.h>
#include "../include/template"
#include "../include/union_find_tree.hpp"

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
