#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int s = 0;
  int b[2][3], c[3][2], board[3][3];
  rep(i, 2) rep(j, 3) {
    cin >> b[i][j];
    s += b[i][j];
  }
  rep(i, 3) rep(j, 2) {
    cin >> c[i][j];
    s += c[i][j];
  }

  auto score = [&]() {
    int sdai = 0, sko = 0;
    rep(i, 2) rep(j, 3) {
      (board[i][j] == board[i + 1][j] ? sdai : sko) += b[i][j];
    }

    rep(i, 3) rep(j, 2) {
      (board[i][j] == board[i][j + 1] ? sdai : sko) += c[i][j];
    }

    return sdai - sko;
  };

  function<int(int)> minimax = [&](int k) {
    if (k == 9) return score();

    if (k % 2 == 0) {
      int m = -1e9;
      rep(i, 3) rep(j, 3) {
        if (board[i][j] != -1) continue;
        board[i][j] = 0;
        chmax(m, minimax(k + 1));
        board[i][j] = -1;
      }
      return m;
    } else {
      int m = 1e9;
      rep(i, 3) rep(j, 3) {
        if (board[i][j] != -1) continue;
        board[i][j] = 1;
        chmin(m, minimax(k + 1));
        board[i][j] = -1;
      }
      return m;
    }
  };

  rep(i, 3) rep(j, 3) board[i][j] = -1;
  int o = minimax(0);
  cout << (s + o) / 2 << endl;
  cout << (s - o) / 2 << endl;

  return 0;
}
