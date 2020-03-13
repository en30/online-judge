#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int c = 0;
  rep(i, n) {
    cin >> a[i];
    c += (a[i] % 2);
  }
  cout << (c == 0 || c == n ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
