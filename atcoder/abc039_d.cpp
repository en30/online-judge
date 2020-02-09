#include <bits/stdc++.h>
#include "../include/template"
#include "../include/grid.hpp"

int main() {
  int H, W;
  cin >> H >> W;
  Grid<char> S(H, W);
  cin >> S;

  Grid<char> T(S);
  rep(i, H) rep(j, W) {
    if (S[i][j] == '.') {
      for (auto& p : T.neighbor8(i, j)) T[p.i][p.j] = '.';
    }
  }

  Grid<char> U(T);
  rep(i, H) rep(j, W) {
    if (T[i][j] == '#') {
      for (auto& p : U.neighbor8(i, j)) U[p.i][p.j] = '#';
    }
  }

  rep(i, H) rep(j, W) {
    if (S[i][j] != U[i][j]) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << "possible" << endl;
  cout << T;

  return 0;
}
