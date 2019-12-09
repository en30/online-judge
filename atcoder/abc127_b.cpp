#include <bits/stdc++.h>
#include "../include/template"

ll r, D, x;
int main() {
  cin >> r >> D >> x;

  rep(i, 10) {
    x = r * x - D;
    cout << x << endl;
  }
  return 0;
}
