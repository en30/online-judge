#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int k, q;
  cin >> k >> q;
  vector<ll> d(k), e(k);
  rep(i, k) cin >> d[i];

  rep(i, q) {
    ll n, x, m;
    cin >> n >> x >> m;

    x %= m;
    rep(i, k) e[i] = d[i] % m;
    ll ans = n - 1, s = accumulate(all(e), 0LL);
    ll l = (n - 1) / k;

    ans -= l * count(all(e), 0LL);
    rep(i, (n - 1) % k) ans -= (e[i] == 0);

    ll y = x + l * s;
    rep(i, (n - 1) % k) y += e[i];
    ans -= y / m - x / m;

    cout << ans << endl;
  }

  return 0;
}
