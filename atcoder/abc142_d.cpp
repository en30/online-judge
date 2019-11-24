#include <bits/stdc++.h>
#include "../include/template"

ll A, B;

struct primeFactor {
  ll p, r;
};

vector<primeFactor> factorization(ll n) {
  vector<primeFactor> res;
  ll m = n;
  for (ll i = 2; i * i <= m; i++) {
    if (m % i) continue;
    primeFactor f = primeFactor{i, 0};
    while (m % i == 0) {
      m /= i;
      f.r++;
    }
    res.push_back(f);
  }
  if (m != 1) {
    res.push_back(primeFactor{m, 1});
  }
  return res;
}

int main() {
  cin >> A >> B;

  vector<primeFactor> fa = factorization(A), fb = factorization(B);
  set<ll> pa, pb, res;
  for (auto &f : fa) pa.insert(f.p);
  for (auto &f : fb) pb.insert(f.p);
  set_intersection(all(pa), all(pb), inserter(res, res.end()));

  cout << res.size() + 1 << endl;
  return 0;
}
