#include <bits/stdc++.h>
#include "../include/template"
#include "../include/max_monoid.hpp"
#include "../include/segment_tree.hpp"

struct Robot {
  int X, D;
  bool operator<(const Robot& that) const { return X < that.X; }
};

int main() {
  const int MOD = 998244353;

  int N;
  cin >> N;
  vector<Robot> R(N);
  rep(i, N) cin >> R[i].X >> R[i].D;

  sort(all(R));

  SegmentTree<MaxMonoid<int>> seg(N);
  for (int i = N - 1; i >= 0; --i) {
    int r = distance(R.begin(), lower_bound(all(R), Robot{R[i].X + R[i].D, 0}));
    seg.update(i, max(i + 1, seg.query(i + 1, max(r, i + 1)).v));
  }

  vector<ll> dp(N, -1);
  function<ll(int)> f = [&](int i) {
    if (i == N) return 1ll;
    if (dp[i] != -1) return dp[i];
    return dp[i] = (f(i + 1) + f(seg.query(i, i + 1).v)) % MOD;
  };

  cout << f(0) << endl;

  return 0;
}
