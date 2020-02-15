#include <bits/stdc++.h>
#include "../include/template"
#include "../include/segment_tree.hpp"

struct Box {
  int i, w, h;
};

int main() {
  int N;
  cin >> N;

  vector<Box> B(N);
  int W = 0;
  rep(i, N) {
    B[i].i = i;
    cin >> B[i].w >> B[i].h;
    chmax(W, B[i].w);
  }

  sort(all(B), [](const Box& a, const Box& b) {
    return a.h == b.h ? a.w > b.w : a.h < b.h;
  });

  SegmentTree<int> seg(
      W + 1, [](int a, int b) { return max(a, b); }, 0);
  int ans = 1;
  rep(i, N) {
    int d = seg.query(0, B[i].w) + 1;
    seg.update(B[i].w, d);
    chmax(ans, d);
  }

  cout << ans << endl;

  return 0;
}
