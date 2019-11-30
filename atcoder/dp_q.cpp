#include <bits/stdc++.h>
#include "../include/template"
#include "../include/segment_tree.hpp"

int N;
vector<int> h, a;

int main() {
  cin >> N;
  h.resize(N), a.resize(N);
  rep(i, N) cin >> h[i];
  rep(i, N) cin >> a[i];

  SegmentTree<ll> seg(
      N + 1, [](ll a, ll b) { return max(a, b); }, 0);

  rep(i, N) {
    ll v = max(seg[h[i]], seg.query(0, h[i]) + a[i]);
    seg.update(h[i], v);
  }

  cout << seg.query(1, N + 1) << endl;
  return 0;
}
