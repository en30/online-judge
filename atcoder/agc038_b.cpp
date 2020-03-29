#include <bits/stdc++.h>
#include "../include/template"
#include "../include/min_monoid.hpp"
#include "../include/max_monoid.hpp"
#include "../include/segment_tree.hpp"

int N, K;
vector<int> P, Q;

int main() {
  cin >> N >> K;
  P.resize(N);
  rep(i, N) cin >> P[i];
  Q = vector<int>(P);

  SegmentTree<MinMonoid<int>> segMin(N);
  SegmentTree<MaxMonoid<int>> segMax(N);

  rep(i, N) {
    segMin.update(i, P[i]);
    segMax.update(i, P[i]);
  }

  int ans = N - K + 1;
  int nStable = 0;
  vector<int> S(N + 1, 0);
  rep(i, N - 1) S[i + 1] = S[i] + (P[i + 1] > P[i]);

  // [l, r]
  auto isStable = [&](int i) { return S[i + K - 1] - S[i] == K - 1; };

  for (int i = 0; i + K <= N; ++i) {
    if (isStable(i)) ++nStable;

    if (i + K == N || (isStable(i) && isStable(i + 1))) continue;
    if (segMin.query(i, i + K).v == P[i] &&
        segMax.query(i + 1, i + 1 + K).v == P[i + K])
      --ans;
  }
  if (nStable > 1) ans -= nStable - 1;

  cout << ans << endl;

  return 0;
}
