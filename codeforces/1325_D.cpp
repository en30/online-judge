#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll u, v;
  cin >> u >> v;

  const int D = 61;
  vector<ll> d(D, 0);
  ll rest = v;
  for (int i = D - 1; i >= 0; --i) {
    if ((u >> i) & 1) {
      d[i] = 1;
      rest -= (1LL << i);
    }
  }
  if (rest < 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = D - 1; i >= 0; --i) {
    ll k = (1LL << i);
    ll m = rest / k;
    if (m % 2) --m;
    d[i] += m;
    rest -= m * k;
  }

  if (rest != 0) {
    cout << -1 << endl;
    return 0;
  }

  ll n = *max_element(all(d));
  cout << n << endl;
  bool printed = false;
  rep(i, n) {
    ll ans = 0;
    rep(i, D) {
      if (d[i] > 0) {
        ans |= (1LL << i);
        --d[i];
      }
    }
    if (printed) printf(" ");
    printf("%lld", ans);
    printed = true;
  }
  if (printed) cout << endl;

  return 0;
}
