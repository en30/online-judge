#include <bits/stdc++.h>
#include "../include/template"

int H, W;

int main() {
  cin >> H >> W;

  vector<vector<char>> grid(H + 2, vector<char>(W + 2, '#'));
  rep(i, H) rep(j, W) cin >> grid[i + 1][j + 1];

  vector<set<int>> row(H), col(W);

  rep(i, H) rep(j, W + 2) if (grid[i + 1][j] == '#') row[i].insert(j);
  rep(j, W) rep(i, H + 2) if (grid[i][j + 1] == '#') col[j].insert(i);

  int ans = 0;
  rep(i, H) rep(j, W) {
    if (grid[i + 1][j + 1] == '#') continue;

    int c = 0;
    auto it = row[i].upper_bound(j + 1);
    c += (*it) - (*prev(it)) - 1;
    it = col[j].upper_bound(i + 1);
    c += (*it) - (*prev(it)) - 1;
    c -= 1;
    ans = max(ans, c);
  }

  cout << ans << endl;

  return 0;
}
