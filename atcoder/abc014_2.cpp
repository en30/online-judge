#include <bits/stdc++.h>
#include "../include/template"

int n, X;

int main() {
  cin >> n >> X;

  ll ans = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if ((X >> i) & 1) ans += a;
  }

  cout << ans << endl;
  return 0;
}
