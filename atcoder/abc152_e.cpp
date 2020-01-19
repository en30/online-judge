#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/prime.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  PrimeTable t(*max_element(all(A)));
  unordered_map<int, int> lcm;
  rep(i, N) {
    auto facts = t.factorize(A[i]);
    for (auto it = facts.begin(); it != facts.end(); it++) {
      lcm[it->first] = max(lcm[it->first], it->second);
    }
  }

  ModInt m = 1;
  for (auto it = lcm.begin(); it != lcm.end(); it++) {
    m *= ModInt(it->first).pow(it->second);
  }

  ModInt ans = 0;
  rep(i, N) ans += m / A[i];

  cout << ans << endl;

  return 0;
}
