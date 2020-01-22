#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/prime.hpp"

ll N, K;

ll sumMultiple(ll n, ll k) {
  ll m = n / k;
  return k * m * (m + 1) / 2;
}

ModInt sumExact(ll n, ll k) {
  auto facts = Prime::factorize(k);
  int M = facts.size();
  ModInt res = 0;
  rep(s, 1LL << M) {
    ll d = 1;
    int r = 0;
    rep(i, M) if (((s >> i) & 1)) {
      d *= facts[i].p;
      ++r;
    };
    if (r % 2 == 0)
      res += sumMultiple(n, d);
    else
      res -= sumMultiple(n, d);
  }
  res *= k;
  return res;
}

int main() {
  cin >> N >> K;
  ModInt ans = 0;

  auto sumGCD = [&](ll d) { return sumExact(N / d, K / d) * d; };

  for (ll d = 1; d * d <= K; ++d) {
    if (K % d != 0) continue;

    ans += sumGCD(d);
    if (d * d != K) ans += sumGCD(K / d);
  }

  cout << ans << endl;
  return 0;
}
