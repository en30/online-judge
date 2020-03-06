#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"

int n;
int X[1010][1010], Y[1010][1010];
char ans[1010][1010];

bool in(int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; }

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int main() {
  cin >> n;
  rep(i, n) rep(j, n) {
    ans[i][j] = '?';
    scanf("%d %d", &X[i][j], &Y[i][j]);
    if (X[i][j] != -1) --X[i][j];
    if (Y[i][j] != -1) --Y[i][j];
  }

  unordered_map<int, unordered_map<int, char>> dir;
  dir[1][0] = 'D';
  dir[-1][0] = 'U';
  dir[0][1] = 'R';
  dir[0][-1] = 'L';

  function<void(int, int, int, int)> sink = [&](int i, int j, int x, int y) {
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (!in(ni, nj)) continue;
      if (ans[ni][nj] != '?') continue;
      if (X[ni][nj] != x || Y[ni][nj] != y) continue;

      ans[ni][nj] = dir[i - ni][j - nj];
      sink(ni, nj, x, y);
    }
  };

  rep(i, n) rep(j, n) {
    if (ans[i][j] != '?') continue;

    if (X[i][j] == -1) {
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (!in(ni, nj)) continue;
        if (X[ni][nj] != -1) continue;
        ans[i][j] = dir[ni - i][nj - j];
        ans[ni][nj] = dir[i - ni][j - nj];
        sink(i, j, -1, -1);
        sink(ni, nj, -1, -1);
      }
    } else {
      if (ans[X[i][j]][Y[i][j]] != '?') break;
      if (X[X[i][j]][Y[i][j]] != X[i][j] || Y[X[i][j]][Y[i][j]] != Y[i][j])
        break;
      ans[X[i][j]][Y[i][j]] = 'X';
      sink(X[i][j], Y[i][j], X[i][j], Y[i][j]);
    }
  }

  rep(i, n) rep(j, n) {
    if (ans[i][j] == '?') {
      cout << "INVALID" << endl;
      return 0;
    }
  }

  cout << "VALID" << endl;
  rep(i, n) {
    rep(j, n) printf("%c", ans[i][j]);
    printf("\n");
  }

  return 0;
}
