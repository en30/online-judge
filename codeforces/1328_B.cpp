#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  ll n, k;
  scanf("%lld %lld", &n, &k);

  ll l = 1, r = n;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (2 * k <= m * (m - 1)) {
      r = m;
    } else {
      l = m;
    }
  }
  ll i = l;
  ll j = n - 1 - (k - (i * (i - 1)) / 2 - 1);
  rep(l, n) printf("%c", (l == (n - 1 - i) || l == j ? 'b' : 'a'));
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
