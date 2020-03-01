#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"

int main() {
  int n, m;
  cin >> m >> n;
  Grid<int> grid(n, m);
  cin >> grid;

  function<int(int, int)> dfs = [&](int i, int j) {
    grid[i][j] = 0;
    int res = 1;
    for (auto& p : grid.neighbor4(i, j)) {
      if (grid[p.i][p.j]) chmax(res, dfs(p.i, p.j) + 1);
    }
    grid[i][j] = 1;
    return res;
  };

  int ans = 0;
  rep(i, n) rep(j, m) {
    if (grid[i][j]) chmax(ans, dfs(i, j));
  }
  cout << ans << endl;

  return 0;
}
