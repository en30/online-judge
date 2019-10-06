#include <bits/stdc++.h>
#include "../include/template"

template <typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) { seg[k + sz] = x; }

  void build() {
    for (int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1) L = f(L, seg[a++]);
      if (b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const { return seg[k + sz]; }
};

int N, K;
vector<int> P, Q;

int main() {
  cin >> N >> K;
  P.resize(N);
  rep(i, N) cin >> P[i];
  Q = vector<int>(P);

  SegmentTree<int> segMin(
      N, [](int a, int b) { return min(a, b); }, INT_MAX),
      segMax(
          N, [](int a, int b) { return max(a, b); }, INT_MIN);

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
    if (segMin.query(i, i + K) == P[i] &&
        segMax.query(i + 1, i + 1 + K) == P[i + K])
      --ans;
  }
  if (nStable > 1) ans -= nStable - 1;

  cout << ans << endl;

  return 0;
}
