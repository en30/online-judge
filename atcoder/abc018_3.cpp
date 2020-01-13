#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int R, C, K;
  cin >> R >> C >> K;

  vector<vector<int>> grid(R, vector<int>(C, 0));
  rep(i, R) rep(j, C) {
    char c;
    cin >> c;
    grid[i][j] = (c == 'o');
  }

  auto good = [&](int i, int j, int k) {
    if (grid[i][j] == 0) return false;
    if (i - 1 < 0 || grid[i - 1][j] < k - 1) return false;
    if (i + 1 >= R || grid[i + 1][j] < k - 1) return false;
    if (j - 1 < 0 || grid[i][j - 1] < k - 1) return false;
    if (j + 1 >= C || grid[i][j + 1] < k - 1) return false;
    return true;
  };

  for (int k = 2; k <= K; ++k) {
    rep(i, R) rep(j, C) {
      if (good(i, j, k)) grid[i][j] = k;
    }
  }

  int ans = 0;
  rep(i, R) rep(j, C) ans += (grid[i][j] == K);
  cout << ans << endl;

  return 0;
}
