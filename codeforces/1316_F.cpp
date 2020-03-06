#include <bits/stdc++.h>
#include "../include/template"
#include "../include/coordinate_compression.hpp"
#include "../include/mod.hpp"
#include "../include/segment_tree.hpp"

vector<pair<int, int>> p(601010);

struct Node {
  ModInt E, L, R, C;
  Node(ModInt E, ModInt L, ModInt R, ModInt C) : E(E), L(L), R(R), C(C) {}
};

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }

  vector<ModInt> pow2(n + 1), ipow2(n + 1);
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

  SegmentTree<Node> seg(
      n + q,
      [&](Node lc, Node rc) {
        return Node(lc.E + rc.E + lc.L * rc.R * ipow2[lc.C.val()],
                    lc.L + pow2[lc.C.val()] * rc.L,
                    lc.R + ipow2[lc.C.val()] * rc.R, lc.C + rc.C);
      },
      Node(0, 0, 0, 0));

  rep(i, n) {
    seg.update(comp.compress(p[i]),
               Node(0, ipow2[1] * p[i].first, p[i].first, 1));
  }

  cout << seg.query(0, n + q).E << endl;
  rep(i, q) {
    seg.update(comp.compress(p[n + i]),
               Node(0, ipow2[1] * p[n + i].first, p[n + i].first, 1));
    seg.update(comp.compress(p[queries[i]]), Node(0, 0, 0, 0));
    p[queries[i]] = p[n + i];
    cout << seg.query(0, n + q).E << endl;
  }

  return 0;
}
