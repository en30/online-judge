#include <bits/stdc++.h>
#include "../include/template"
#include "../include/coordinate_compression.hpp"
#include "../include/binary_indexed_tree.hpp"

struct Point {
  int x, v;
};

int main() {
  int n;
  cin >> n;

  vector<int> x(n), v(n);
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> v[i];
  CoordinateCompression<int> ccx(x);

  vector<Point> P(n);
  rep(i, n) {
    P[i].x = x[i];
    P[i].v = v[i];
  }

  sort(all(P), [](const Point &a, const Point &b) {
    return a.v == b.v ? a.x < b.x : a.v < b.v;
  });

  ll ans = 0;
  BinaryIndexedTree<ll> bitC(ccx.size()), bitX(ccx.size());
  rep(i, n) {
    int cx = ccx.compress(P[i].x);
    ans += bitC.sum(cx) * P[i].x - bitX.sum(cx);
    bitC.add(cx, 1);
    bitX.add(cx, P[i].x);
  }

  cout << ans << endl;
  return 0;
}
