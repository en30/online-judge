#include <bits/stdc++.h>
#include "../include/template"

int A, B, C, D;

int main() {
  cin >> A >> B >> C >> D;
  int ans = 0;
  bool a = false, b = false;
  rep(i, 101) {
    a = (A <= i && i <= B);
    b = (C <= i && i <= D);
    if (a & b) ans++;
  }
  if (ans != 0) ans--;
  cout << ans << endl;
  return 0;
}
