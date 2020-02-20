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

  for (ll b = 2; b <= sqrt(n); ++b) {
    if (f(b, n) == s) {
      cout << b << endl;
      return 0;
    }
  }

  const ll INF = 1e18;
  ll ans = INF;
  for (ll p = 1; p < sqrt(n); ++p) {
    ll b = (n - s) / p + 1;
    if (b > 1 && f(b, n) == s) chmin(ans, b);
  }

  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
