#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
  } else if ((b > a) ^ ((a - b) % 2 == 0)) {
    cout << 1 << endl;
  } else {
    cout << 2 << endl;
  }
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
