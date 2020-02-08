#include <bits/stdc++.h>
#include "../include/template"
#include "../include/gcd.hpp"

int N, M;

int main() {
  cin >> N >> M;

  set<int> a;

  set<int> b;
  rep(i, N) {
    int k;
    cin >> k;
    k /= 2;
    a.insert(k);
    int j = 0;
    while (((k >> j) & 1) == 0) ++j;
    b.insert(j);
  }

  if (b.size() >= 2) {
    cout << 0 << endl;
    return 0;
  }

  ll cm = 1;
  for (auto it = a.begin(); it != a.end(); it++) {
    cm = lcm(cm, *it);
  }

  int ans = (M / cm + 1) / 2;

  cout << ans << endl;

  return 0;
}
