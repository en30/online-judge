#include <bits/stdc++.h>
#include "../include/template"
#include "../include/union_find_tree.hpp"

int main() {
  int n, q;

  cin >> n >> q;

  UnionFindTree uft(n);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) {
      uft.unite(x, y);
      continue;
    }
    cout << uft.same(x, y) << endl;
  }

  return 0;
}
