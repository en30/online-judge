#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt<1000000007>;

ll N;

int main() {
  cin >> N;

  vector<ll> c(60, 0);

  rep(i, N) {
    ll A;
    cin >> A;
    rep(j, 60) {
      if ((A >> j) & 1) c[j] += 1;
    }
  }

  mint ans = 0;
  rep(i, 60) {
    mint m = c[i] * (N - c[i]);
    m *= (1LL << i);
    ans += m;
  }

  cout << ans << endl;

  return 0;
}
