#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  sort(all(a)), sort(all(b));
  rep(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  rep(i, n) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
