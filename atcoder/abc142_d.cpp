#include <bits/stdc++.h>
#include "../include/template"
#include "../include/prime.hpp"

ll A, B;

int main() {
  cin >> A >> B;

  auto fa = Prime::factorize(A), fb = Prime::factorize(B);
  set<ll> pa, pb, res;
  for (auto &f : fa) pa.insert(f.p);
  for (auto &f : fb) pb.insert(f.p);
  set_intersection(all(pa), all(pb), inserter(res, res.end()));

  cout << res.size() + 1 << endl;
  return 0;
}
