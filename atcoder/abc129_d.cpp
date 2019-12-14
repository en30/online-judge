#include <bits/stdc++.h>
#include "../include/template"

int H, W;

int main() {
  cin >> H >> W;

  vector<vector<char>> grid(H + 2, vector<char>(W + 2, '#'));
  rep(i, H) rep(j, W) cin >> grid[i + 1][j + 1];

  vector<vector<vector<int>>> C(H + 2,
                                vector<vector<int>>(W + 2, vector<int>(4, 0)));

  for (int i = 1; i <= H; ++i)
    for (int j = 1; j <= W; ++j) {
      if (grid[i][j] == '#') {
        C[i][j][0] = 0;
      } else {
        C[i][j][0] = C[i][j - 1][0] + 1;
      }
      if (grid[i][W - j + 1] == '#') {
        C[i][W - j + 1][1] = 0;
      } else {
        C[i][W - j + 1][1] = C[i][W - j + 2][1] + 1;
      }
    }

  for (int j = 1; j <= W; ++j)
    for (int i = 1; i <= H; ++i) {
      if (grid[i][j] == '#') {
        C[i][j][2] = 0;
      } else {
        C[i][j][2] = C[i - 1][j][2] + 1;
      }
      if (grid[H - i + 1][j] == '#') {
        C[H - i + 1][j][3] = 0;
      } else {
        C[H - i + 1][j][3] = C[H - i + 2][j][3] + 1;
      }
    }

  int ans = 0;
  rep(i, H) rep(j, W) {
    if (grid[i + 1][j + 1] == '#') continue;
    ans = max(ans, accumulate(all(C[i][j]), 0) - 3);
  }

  cout << ans << endl;

  return 0;
}
