#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int R, C;
  cin >> R >> C;

  vector<bitset<10>> cols(C, 0);
  rep(r, R) rep(c, C) {
    int a;
    cin >> a;
    cols[c][r] = a;
  }

  int ans = 0;
  rep(s, (1 << R)) {
    int res = R * C;
    bitset<10> flip(s);
    rep(c, C) {
      int k = (flip ^ cols[c]).count();
      res -= min(k, R - k);
    }
    chmax(ans, res);
  }

  cout << ans << endl;

  return 0;
}
