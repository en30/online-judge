#include <bits/stdc++.h>
#include "../include/template"
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

  SegmentTree<ll> segC(
      vals.size() + 1, [](ll a, ll b) { return a + b; }, 0),
      segV(
          vals.size() + 1, [](ll a, ll b) { return a + b; }, 0);

  int n = 0;
  ll offset = 0;
  rep(i, Q) {
    if (qs[i].type == 1) {
      int j = distance(vals.begin(), lower_bound(all(vals), qs[i].a));
      segC.update(j, segC[j] + 1);
      segV.update(j, segV[j] + qs[i].a);
      ++n;
      offset += qs[i].b;
    } else {
      int j = segC.find_first(0, [&](ll v) { return v >= (n + 1) / 2; });
      int x = vals[j];
      ll y = offset;
      y += x * segC.query(0, j) - segV.query(0, j);
      y += -x * segC.query(j, vals.size() + 1) + segV.query(j, vals.size() + 1);
      cout << x << " " << y << endl;
    }
  }

  return 0;
}
