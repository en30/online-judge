#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  cout << min(m, accumulate(all(a), 0)) << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
