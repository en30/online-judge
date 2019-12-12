#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

ll L, R;

using mint = ModInt;

mint dp[61][2][2][2];

int main() {
  cin >> L >> R;

  dp[60][0][0][0] = 1;
  for (int i = 59; i >= 0; i--) {
    int lb = (L >> i) & 1;
    int rb = (R >> i) & 1;

    rep(j, 2) rep(k, 2) rep(l, 2) {
      mint pre = dp[i + 1][j][k][l];
      rep(x, 2) rep(y, 2) {
        if (x && !y) continue;

        int nj = j, nk = k, nl = l;
        if (!l && x != y) continue;
        if (x && y) nl = 1;

        if (!j && !x && lb) continue;
        if (x && !lb) nj = 1;

        if (!k && y && !rb) continue;
        if (!y && rb) nk = 1;

        dp[i][nj][nk][nl] += pre;
      }
    }
  }

  mint ans = 0;
  rep(j, 2) rep(k, 2) rep(l, 2) ans += dp[0][j][k][l];
  cout << ans << endl;
  return 0;
}
