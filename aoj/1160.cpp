#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    Grid<int> grid(h, w);
    cin >> grid;

    function<void(int, int)> dfs = [&](int i, int j) {
      grid[i][j] = 0;
      for (auto& p : grid.neighbor8(i, j)) {
        if (grid[p.i][p.j]) dfs(p.i, p.j);
      };
    };

    int ans = 0;
    rep(i, h) rep(j, w) {
      if (grid[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
