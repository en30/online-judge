#include <bits/stdc++.h>
#include "../include/template"

int t;

void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;

  int t = 0;
  bool changed = true;
  while (changed) {
    changed = false;

    rep(i, k - 1) {
      if (s[i] == 'A' && s[i + 1] == 'P') {
        s[i + 1] = 'A';
        ++i;
        changed = true;
      }
    }
    if (changed) ++t;
  }
  cout << t << endl;
}

int main() {
  cin >> t;
  rep(i, t) solve();
  return 0;
}
