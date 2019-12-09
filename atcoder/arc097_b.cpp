#include <bits/stdc++.h>
#include "../include/template"
#include "../include/union_find_tree.hpp"

int N, M;
vector<int> p;

int main() {
  cin >> N >> M;
  p.resize(N);
  rep(i, N) {
    cin >> p[i];
    p[i]--;
  }

  UnionFindTree t(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.unite(x, y);
  }

  int ans = 0;
  rep(i, N) { ans += t.same(i, p[i]); }
  cout << ans << endl;
  return 0;
}
