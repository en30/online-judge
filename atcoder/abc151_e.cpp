#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

int N, K;
vector<int> A;
int main() {
  cin >> N >> K;
  A.resize(N);
  rep(i, N) cin >> A[i];

  sort(all(A));

  Combination<ModInt> comb(N);

  ModInt ans = 0;
  rep(i, N) {
    ans += comb.C(i, K - 1) * A[i];
    ans -= comb.C(N - 1 - i, K - 1) * A[i];
  }

  cout << ans << endl;

  return 0;
}
