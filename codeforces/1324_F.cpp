#include <bits/stdc++.h>
#include "../include/template"
#include "../include/re_rooting.hpp"

vector<int> a;
struct Monoid {
  int v;
  bool operator==(const Monoid& that) const { return v == that.v; }
  bool operator!=(const Monoid& that) const { return !(*(this) == that); }

  static Monoid identity(int u) { return Monoid(0); }

  Monoid(int v = 1e9) : v(v) {}
  Monoid& operator+=(const Monoid& that) {
    v = max(v, 0) + max(that.v, 0);
    return *this;
  }
  Monoid operator+(const Monoid& that) const { return Monoid(*this) += that; }

  Monoid addRoot(int u) const { return Monoid(v + 2 * a[u] - 1); }
};

int main() {
  int n;
  cin >> n;

  a.resize(n);
  rep(i, n) scanf("%d", &a[i]);

  vector<vector<int>> G(n);
  rep(i, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ReRooting<Monoid> mws(G);

  for (int i = 0; i < (int)(n); ++i) {
    if (i) cout << " ";
    cout << mws.value(i, -1).v;
  }
  cout << endl;

  return 0;
}
