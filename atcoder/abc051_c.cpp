#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  string ans = "";
  ans += string(ty - sy, 'U') + string(tx - sx, 'R');
  ans += string(ty - sy, 'D') + string(tx - sx, 'L');
  ans += "L" + string(ty - sy + 1, 'U') + string(tx - sx + 1, 'R') + "D";
  ans += "R" + string(ty - sy + 1, 'D') + string(tx - sx + 1, 'L') + "U";
  cout << ans << endl;

  return 0;
}
