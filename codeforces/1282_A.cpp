#include <bits/stdc++.h>
#include "../include/template"

int t;

void solve() {
  int a, b, c, r;
  cin >> a >> b >> c >> r;
  if (b < a) swap(a, b);
  int ans = b - a;
  if (c + r > a && c - r < b) {
    ans -= (min(c + r, b) - max(c - r, a));
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  rep(i, t) solve();
  return 0;
}
