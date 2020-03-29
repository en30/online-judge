#include <bits/stdc++.h>
#include "../include/template"
#include "../include/max_monoid.hpp"
#include "../include/segment_tree.hpp"

int N;
vector<int> h, a;

int main() {
  cin >> N;
  h.resize(N), a.resize(N);
  rep(i, N) cin >> h[i];
  rep(i, N) cin >> a[i];

  SegmentTree<MaxMonoid<ll, 0>> seg(N + 1);

  rep(i, N) {
    ll v = max(seg.at(h[i]).v, seg.query(0, h[i]).v + a[i]);
    seg.update(h[i], v);
  }

  cout << seg.query(1, N + 1).v << endl;
  return 0;
}
