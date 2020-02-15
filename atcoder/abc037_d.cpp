#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"
#include "../include/mod.hpp"

struct Cell {
  int a, i, j;
};

int main() {
  int H, W;
  cin >> H >> W;

  Grid<int> a(H, W);
  cin >> a;

  vector<Cell> cells;
  rep(i, H) rep(j, W) { cells.push_back(Cell{a[i][j], i, j}); }

  sort(all(cells), [](const Cell& a, const Cell& b) { return a.a < b.a; });
  vector<vector<ModInt>> c(H, vector<ModInt>(W, 1));
  for (auto& cell : cells) {
    for (auto& p : a.neighbor4(cell.i, cell.j)) {
      if (a[p.i][p.j] > a[cell.i][cell.j]) {
        c[p.i][p.j] += c[cell.i][cell.j];
      }
    }
  }

  ModInt ans = 0;
  rep(i, H) rep(j, W) ans += c[i][j];
  cout << ans << endl;

  return 0;
}
