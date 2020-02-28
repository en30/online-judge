#include <bits/stdc++.h>
#include "../include/template"
#include "../include/bit_manipulation.hpp"

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  ll ans = 1e18;

  int s = first_fixed_size_subset(N, K);
  do {
    ll cost = 0, prev = 0;
    rep(i, N) {
      if ((s >> i) & 1) {
        ll h = max(a[i], prev + 1);
        cost += h - a[i];
        prev = h;
      } else {
        chmax(prev, a[i]);
      }
    }
    chmin(ans, cost);
  } while (next_fixed_size_subset(N, K, s));

  cout << ans << endl;
  return 0;
}
