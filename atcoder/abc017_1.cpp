#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int ans = 0;
  rep(i, 3) {
    int s, e;
    cin >> s >> e;
    ans += s * e / 10;
  }
  cout << ans << endl;
  return 0;
}
