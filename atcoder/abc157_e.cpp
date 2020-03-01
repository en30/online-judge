#include <bits/stdc++.h>
#include "../include/template"
#include "../include/segment_tree.hpp"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int Q;
  cin >> Q;

  SegmentTree<int> seg(
      N, [](int a, int b) { return a | b; }, 0);
  rep(i, N) { seg.update(i, 1 << (S[i] - 'a')); }

  rep(i, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      int s = seg[i];
      s = s & ~(1 << (S[i] - 'a'));
      s |= 1 << (c - 'a');
      S[i] = c;
      seg.update(i, s);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << __builtin_popcount(seg.query(l, r + 1)) << endl;
    }
  }
  return 0;
}
