#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  string s;
  cin >> s;
  s = s + 'R';
  int p = -1, d = 0;
  rep(i, s.size()) {
    if (s[i] == 'R') {
      chmax(d, i - p);
      p = i;
    }
  }
  cout << d << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();

  return 0;
}
