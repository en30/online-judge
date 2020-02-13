#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  ll n, g, b;
  cin >> n >> g >> b;
  ll k = (n + 1) / 2;
  ll ans = 0;
  if (k % g == 0) {
    ans = (k / g - 1) * (g + b) + g;
  } else {
    ans = (k / g) * (g + b) + k % g;
  }
  cout << max(ans, n) << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) solve();
  return 0;
}
