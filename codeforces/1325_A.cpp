#include <bits/stdc++.h>
#include "../include/template"
#include "../include/divisor.hpp"
#include "../include/gcd.hpp"

void solve() {
  ll x;
  scanf("%lld", &x);
  auto ds = divisor(x);

  for (ll a : ds) {
    ll b = a * (x - a);
    if (gcd(a, b) == a) {
      printf("%lld %lld\n", a, b);
      return;
    }
  }
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
