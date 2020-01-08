#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/lazy_segment_tree.hpp"

int N, M;
vector<int> f;

int main() {
  cin >> N >> M;

  f.resize(N);

  rep(i, N) cin >> f[i];

  vector<ModInt> dp(N + 1, 0);

  dp[N] = ModInt(1);

  unordered_map<int, int> m;

  LazySegmentTree<ModInt, ModInt> t(
      N + 1, [](ModInt a, ModInt b) { return a + b; },
      [](ModInt a, ModInt b) { return a + b; },
      [](ModInt a, ModInt b) { return a + b; }, 0, 0);

  t.update(N, N + 1, ModInt(1));

  int l = N - 1, r = N;
  while (r > 0) {
    while (l >= 0 && !m[f[l]]) {
      m[f[l]] += 1;
      --l;
    }
    do {
      t.update(l + 1, r, t[r]);
      --r;
      m[f[r]] -= 1;
    } while (r > l && m[f[l]]);
  }

  cout << t[0] << endl;

  return 0;
}
