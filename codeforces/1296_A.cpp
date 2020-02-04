#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  cin >> n;
  vector<int> c(2, 0);
  rep(i, n) {
    int a;
    cin >> a;
    ++c[a % 2];
  }
  cout << ((c[1] == n && n % 2 == 1) || (c[1] >= 1 && c[0] >= 1) ? "YES" : "NO")
       << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
