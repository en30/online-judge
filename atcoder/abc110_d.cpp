#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/combination.hpp"

using mint = ModInt<1000000007>;

struct primeFactor {
  int p, r;
};

vector<primeFactor> factorization(int n) {
  vector<primeFactor> res;
  int m = n;
  for (int i = 2; i * i <= m; i++) {
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
  int N, M;
  cin >> N >> M;

  int K = N + 40;

  Combination<mint> comb(K);

  mint ans = 1;
  auto facts = factorization(M);
  for (auto f : facts) {
    ans *= comb.H(N, f.r);
  }

  cout << ans << endl;

  return 0;
}
