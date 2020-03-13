#include <bits/stdc++.h>
#include "../include/template"
#include "../include/coordinate_compression.hpp"
#include "../include/binary_indexed_tree.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) scanf("%d", &a[i]);
  rep(i, n) scanf("%d", &b[i]);
  rep(i, n) c[i] = a[i] - b[i];
  sort(all(c));

  CoordinateCompression<int> comp(c);
  BinaryIndexedTree<int> bit(comp.size());
  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int j = distance(c.begin(), upper_bound(all(c), b[i] - a[i]));
    if (j < n) ans += bit.sum(comp.compress(c[j]), comp.size());
    bit.add(comp.compress(a[i] - b[i]), 1);
  }

  cout << ans << endl;

  return 0;
}
