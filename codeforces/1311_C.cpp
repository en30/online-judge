#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> c(n + 1, 0);
  rep(i, m) {
    int p;
    cin >> p;
    c[0] += 1;
    c[p] -= 1;
  }
  c[0] += 1;
  c[n] -= 1;

  rep(i, n) c[i + 1] += c[i];

  vector<ll> ans(26, 0);
  rep(i, n) ans[s[i] - 'a'] += c[i];
  rep(i, 26) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
