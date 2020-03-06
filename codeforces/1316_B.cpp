#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<pair<string, int>> t(n);
  rep(i, n) {
    t[i] = make_pair(s.substr(i, n - i) + s.substr(0, i), i + 1);
    if ((n - i) % 2) reverse(t[i].first.begin() + n - i, t[i].first.end());
  }
  sort(all(t));
  cout << t[0].first << endl;
  cout << t[0].second << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
