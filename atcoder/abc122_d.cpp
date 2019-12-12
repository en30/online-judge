#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

// A  C  G  T
// 00 01 10 11

// .A.G.C.
// ?AGC A?GC ?GAC ?ACG AG?C

int masks[5] = {0b00111111, 0b11001111, 0b00111111, 0b00111111, 0b11110011};
int patterns[5] = {0b00001001, 0b00001001, 0b00100001, 0b00000110, 0b00100001};

const int S = 4 * 4 * 4;

bool ok(int s) {
  rep(i, 5) {
    if ((s & masks[i]) == patterns[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  using mint = ModInt;

  vector<vector<mint>> dp(S, vector<mint>(n + 1, 0));
  dp[0b111111][0] = 1;

  rep(i, n) {
    rep(j, S) {
      rep(k, 4) {
        int s = (j << 2) | k;
        if (ok(s)) {
          dp[s & 0b111111][i + 1] += dp[j][i];
        }
      }
    }
  }

  mint ans = 0;
  rep(i, S) ans += dp[i][n];
  cout << ans << endl;

  return 0;
}
