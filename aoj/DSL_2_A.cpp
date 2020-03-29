#include <bits/stdc++.h>
#include "../include/template"
#include "../include/min_monoid.hpp"
#include "../include/segment_tree.hpp"

int main() {
  int n, q;
  cin >> n >> q;

  SegmentTree<MinMonoid<int>> seg(n);
  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      cout << seg.query(x, y + 1).v << endl;
    } else {
      seg.update(x, y);
    }
  }

  return 0;
}
