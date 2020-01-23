#include <bits/stdc++.h>
#include "../include/template"
#include "../include/segment_tree.hpp"

int main() {
  int q, x;
  cin >> q >> x;

  SegmentTree<int> t(
      x, [](int a, int b) { return min(a, b); }, 1e9);
  rep(i, x) t.update(i, 0);
  rep(i, q) {
    int y;
    cin >> y;
    y %= x;
    t.update(y, t[y] + 1);
    int m = t.query(0, x);
    int k = t.find_first(0, [&](auto z) { return z <= m; });
    cout << m * x + k << endl;
  }

  return 0;
}
