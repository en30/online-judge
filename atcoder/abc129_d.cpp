#include <bits/stdc++.h>
#include "../include/template"

int H, W;

int main() {
  cin >> H >> W;

  vector<vector<char>> grid(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> grid[i][j];

  vector<vector<int>> C(H, vector<int>(W, 0));

  rep(i, H) {
    int l = 1, r = 1;
    rep(j, W) {
      if (grid[i][j] == '#') l = 0;
      C[i][j] += l++;
      if (grid[i][W - 1 - j] == '#') r = 0;
      C[i][W - 1 - j] += r++;
    }
  }

  rep(j, W) {
    int u = 1, d = 1;
    rep(i, H) {
      if (grid[i][j] == '#') u = 0;
      C[i][j] += u++;
      if (grid[H - 1 - i][j] == '#') d = 0;
      C[H - 1 - i][j] += d++;
    }
  }

  int ans = 0;
  rep(i, H) rep(j, W) {
    if (grid[i][j] == '#') continue;
    ans = max(ans, C[i][j] - 3);
  }

  cout << ans << endl;

  return 0;
}
