#include <bits/stdc++.h>
#include "../include/template"
#include "../include/binary_search.hpp"
#include "../include/min_monoid.hpp"
#include "../include/segment_tree.hpp"

int main() {
  int q, x;
  cin >> q >> x;

  SegmentTree<MinMonoid<int>> t(x);
  rep(i, x) t.update(i, 0);

  rep(i, q) {
    int y;
    cin >> y;
    y %= x;
    t.update(y, t.at(y).v + 1);
    int m = t.query(0, x).v;
    int k = integer_partition_point<int>(
        0, t.size(), [&](int i) { return t.query(0, i).v > m; });

    cout << m * x + k << endl;
  }

  return 0;
}
