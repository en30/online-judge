#include <bits/stdc++.h>
#include "../include/template"
#include "../include/binary_search.hpp"
#include "../include/addition_monoid.hpp"
#include "../include/segment_tree.hpp"

int Q;

struct Query {
  int type, a, b;
};

int main() {
  cin >> Q;

  vector<Query> qs(Q);
  vector<int> vals;
  rep(i, Q) {
    cin >> qs[i].type;
    if (qs[i].type == 2) continue;
    cin >> qs[i].a >> qs[i].b;
    vals.push_back(qs[i].a);
  }
  sort(all(vals));
  vals.erase(unique(all(vals)), vals.end());

  SegmentTree<AdditionMonoid<ll>> segC(vals.size() + 1), segV(vals.size() + 1);

  int n = 0;
  ll offset = 0;
  rep(i, Q) {
    if (qs[i].type == 1) {
      int j = distance(vals.begin(), lower_bound(all(vals), qs[i].a));
      segC.add(j, 1);
      segV.add(j, qs[i].a);
      ++n;
      offset += qs[i].b;
    } else {
      int j = integer_partition_point<int>(0, segC.size(), [&](int k) {
        return segC.query(0, k).v < (n + 1) / 2;
      });
      int x = vals[j];
      ll y = offset;
      y += x * segC.query(0, j).v - segV.query(0, j).v;
      y += -x * segC.query(j, segC.size()).v + segV.query(j, segV.size()).v;
      cout << x << " " << y << endl;
    }
  }

  return 0;
}
