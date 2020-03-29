#include <bits/stdc++.h>
#include "../include/template"
#include "../include/coordinate_compression.hpp"
#include "../include/mod.hpp"
#include "../include/segment_tree.hpp"

vector<pair<int, int>> p(601010);
vector<ModInt> pow2, ipow2;

struct Monoid {
  ModInt E, L, R, C;

  static Monoid identity() { return Monoid(0, 0, 0, 0); }

  Monoid(ModInt E, ModInt L, ModInt R, ModInt C) : E(E), L(L), R(R), C(C) {}
  Monoid& operator+=(const Monoid& that) {
    E += that.E + L * that.R * ipow2[C.val()];
    L += pow2[C.val()] * that.L;
    R += ipow2[C.val()] * that.R;
    C += that.C;
    return *this;
  }
  Monoid operator+(const Monoid& that) const { return Monoid(*this) += that; }
};

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }

  pow2.resize(n + 1), ipow2.resize(n + 1);
  rep(i, n) {
    pow2[i] = ModInt(2).pow(i);
    ipow2[i] = pow2[i].inverse();
  }

  int q;
  cin >> q;
  vector<int> queries(q);
  p.resize(n + q);
  rep(j, q) {
    int i, x;
    scanf("%d %d", &i, &p[n + j].first);
    --i;
    p[n + j].second = n + j;
    queries[j] = i;
  }

  CoordinateCompression<pair<int, int>> comp(p);

  SegmentTree<Monoid> seg(n + q);

  rep(i, n) {
    seg.update(comp.compress(p[i]),
               Monoid(0, ipow2[1] * p[i].first, p[i].first, 1));
  }

  cout << seg.query(0, n + q).E << endl;
  rep(i, q) {
    seg.update(comp.compress(p[n + i]),
               Monoid(0, ipow2[1] * p[n + i].first, p[n + i].first, 1));
    seg.update(comp.compress(p[queries[i]]), Monoid(0, 0, 0, 0));
    p[queries[i]] = p[n + i];
    cout << seg.query(0, n + q).E << endl;
  }

  return 0;
}
