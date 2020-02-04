#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int s;
  cin >> s;
  int ans = 0;
  while (s != 0) {
    int x = (s >= 10 ? (s / 10) * 10 : s);
    ans += x;
    s = s - x + x / 10;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
