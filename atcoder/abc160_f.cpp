#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"
#include "../include/re_rooting.hpp"

Combination<ModInt> comb;

struct Monoid {
  int c;
  ModInt m;
  bool operator==(const Monoid& that) const {
    return c == that.c && m == that.m;
  }
  bool operator!=(const Monoid& that) const { return !(*(this) == that); }

  static Monoid identity(int i) { return Monoid{0, 1}; }

  Monoid() : c(-1), m(0) {}
  Monoid(int c, ModInt m) : c(c), m(m) {}
  Monoid operator+(const Monoid& that) const {
    return Monoid{c + that.c, m * that.m * comb.C(c + that.c, that.c)};
  }

  Monoid addRoot(int u) {
    Monoid s = Monoid(*this);
    s.c += 1;
    return s;
  }
};

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  comb.resize(N);

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ReRooting<Monoid> rr(G);

  rep(i, N) cout << rr.value(i, -1).m << endl;

  return 0;
}
