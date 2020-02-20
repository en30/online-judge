#include <bits/stdc++.h>
#include "../include/template"

ll f(ll b, ll n) {
  ll res = 0, k = n;
  do {
    res += k % b;
    k /= b;
  } while (k);
  return res;
}

int main() {
  ll n, s;
  cin >> n >> s;

  if (n == s) {
    cout << n + 1 << endl;
    return 0;
  }

  const ll INF = 1e18;
  auto find = [&](ll k, ll l, ll r) {
    ll vl = f(r, n);
    if (vl % k != s % k) return INF;
    ll vr = f(l + 1, n);
    if (vl <= s && s <= vr) return r - (s - vl) / k;
    return INF;
  };

  ll ans = INF;
  ll i = 1;

  while (n / (i + 1) != 0 && n / (i + 1) != n / i) {
    chmin(ans, find(i, n / (i + 1), n / i));
    ++i;
  }
  for (ll j = n / i; j >= 2; --j) {
    if (f(j, n) == s) ans = j;
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
