#include <bits/stdc++.h>
#include "../include/template"
#include "../include/undirected_tree.hpp"
#include "../include/re_rooting.hpp"

using Result = pair<int, int>;

struct Monoid {
  pair<int, int> v;
  bool operator==(const Monoid& that) const { return v == that.v; }
  bool operator!=(const Monoid& that) const { return !(*(this) == that); }

  static Monoid identity(int u) { return Monoid{make_pair(0, u)}; };

  Monoid() : v(-1, -1) {}
  Monoid(pair<int, int> v) : v(v) {}
  Monoid& operator+=(const Monoid& that) {
    v = max(v, that.v);
    return *this;
  }
  Monoid operator+(const Monoid& that) const { return Monoid(*this) += that; }

  Monoid addRoot(int u) {
    Monoid res(*this);
    res.v.first += 1;
    return res;
  }

  bool operator<(const Monoid& that) const { return v < that.v; }
};

int main() {
  int N;
  cin >> N;

  UndirectedTree T(N);
  cin >> T;

  ReRooting<Monoid> r(T.adjacencyList());

  int d = 0;
  vector<Monoid> s;
  rep(u, N) {
    if (T[u].size() < 2) continue;

    priority_queue<Monoid> pq;
    pq.push(Result(0, u));
    for (auto v : T[u]) pq.push(r.value(v, u));
    vector<Monoid> curr;
    rep(i, 3) {
      curr.push_back(pq.top());
      pq.pop();
    }
    int cd = 0;
    for (auto& p : curr) cd += p.v.first;
    if (chmax(d, cd)) s = curr;
  }

  cout << d << endl;
  cout << (s[0].v.second + 1) << " " << (s[1].v.second + 1) << " "
       << (s[2].v.second + 1) << endl;

  return 0;
}
