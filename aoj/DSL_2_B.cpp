#include <bits/stdc++.h>
#include "../include/template"
#include "../include/addition_monoid.hpp"
#include "../include/segment_tree.hpp"

int main() {
  int n, q;
  cin >> n >> q;

  SegmentTree<AdditionMonoid<int>> seg(n);
  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      --x, --y;
      cout << seg.query(x, y + 1).v << endl;
    } else {
      --x;
      seg.add(x, y);
    }
  }

  return 0;
}
