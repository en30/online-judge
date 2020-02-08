#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int N;
vector<int> C;

int main() {
  cin >> N;
  C.resize(N);
  rep(i, N) cin >> C[i];
  sort(all(C));

  ModInt ans = 0;
  rep(i, N) { ans += ll(N + 1 - i) * C[i]; }
  ans *= ModInt(2).pow(2 * N - 2);
  cout << ans << endl;

  return 0;
}
