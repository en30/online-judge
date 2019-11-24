#include <bits/stdc++.h>
#include "../include/template"

int X, Y;

int f(int i) {
  if (i == 1) return 300000;
  if (i == 2) return 200000;
  if (i == 3) return 100000;
  return 0;
}

int main() {
  cin >> X >> Y;
  int ans = f(X) + f(Y);
  if (X == 1 && Y == 1) ans += 400000;

  cout << ans << endl;
  return 0;
}
