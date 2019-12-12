#include <bits/stdc++.h>
#include "../include/template"
#include "../include/lazy_segment_tree.hpp"

int N, M;

// [l, r]
struct Section {
  int l, r, a;
};

int main() {
  cin >> N >> M;

  vector<vector<Section>> S(N);
  rep(i, M) {
    int l, r, a;
    cin >> l >> r >> a;
    --l, --r;
    S[r].push_back(Section{l, r, a});
  }

  LazySegmentTree<ll, ll> t(
      N, [](ll a, ll b) { return max(a, b); }, [](ll a, ll r) { return a + r; },
      [](ll a, ll b) { return a + b; }, 0, 0);

  rep(i, N) {
    t.set(i, t.query(0, i));
    for (auto &s : S[i]) t.update(s.l, i + 1, s.a);
  }

  cout << t.query(0, N) << endl;

  return 0;
}
