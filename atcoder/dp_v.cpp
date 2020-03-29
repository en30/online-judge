#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"
#include "../include/re_rooting.hpp"

int N, M;

struct Monoid {
  ll c;
  bool operator==(const Monoid& that) const { return c == that.c; }
  bool operator!=(const Monoid& that) const { return !(*(this) == that); }

  static Monoid identity(int i) { return Monoid{1}; }

  Monoid() : c(-1) {}
  Monoid(ll c) : c(c) {}
  Monoid& operator+=(const Monoid& that) {
    c *= that.c;
    c %= M;
    return *this;
  }
  Monoid operator+(const Monoid& that) const { return Monoid(*this) += that; }

  Monoid addRoot(int u) { return Monoid{c + 1}; }
};

int main() {
  cin >> N >> M;

  UndirectedTree T(N);
  cin >> T;

  ReRooting<Monoid> subtreeCount(T.adjacencyList());
  rep(i, N) cout << subtreeCount.value(i, -1).c - 1 << endl;

  return 0;
}
