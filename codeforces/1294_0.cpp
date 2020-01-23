#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int ideal = (a + b + c + n) / 3;
  if((a + b + c + n) % 3 == 0 && ideal >= a && ideal >= b && ideal >= c) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}

int main () {
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
