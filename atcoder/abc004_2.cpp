#include <bits/stdc++.h>
#include "../include/template"

char c[4][4];
int main() {
  rep(i, 4) rep(j, 4) cin >> c[i][j];

  rep(i, 4) {
    rep(j, 4) {
      cout << c[3 - i][3 - j];
      if (j == 3) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
  return 0;
}
