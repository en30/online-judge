#include <bits/stdc++.h>
#include "../include/template"

int H, W;

int dp[80][80][80 * 160 + 1];

struct P {
  int x, y;
};

int main() {
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];
  rep(i, H) rep(j, W) cin >> B[i][j];

  dp[0][0][0] = 1;
  rep(i, H) rep(j, W) {
    int d = abs(A[i][j] - B[i][j]);
    rep(k, 80 * 160 + 1) {
      if (dp[i][j][k]) {
        if (i + 1 < H) {
          dp[i + 1][j][abs(k - d)] = 1;
          dp[i + 1][j][k + d] = 1;
        }
        if (j + 1 < W) {
          dp[i][j + 1][abs(k - d)] = 1;
          dp[i][j + 1][k + d] = 1;
        }
      }
    }
  }

  int ans = 1e9;
  int d = abs(A[H - 1][W - 1] - B[H - 1][W - 1]);
  rep(k, 80 * 160 + 1) {
    if (dp[H - 1][W - 1][k]) ans = min(ans, abs(k - d));
  }
  cout << ans << endl;

  return 0;
}
