#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

using mint = ModInt<1000000007>;

int main() {
  int N, K;
  cin >> N >> K;

  Combination<mint> comb(N + 1);

  for (int i = 1; i <= K; i++) {
    if (N - K - i + 1 < 0) {
      cout << 0 << endl;
      continue;
    }
    cout << comb.C(N - K + 1, i) * comb.C(K - 1, i - 1) << endl;
  }

  return 0;
}
