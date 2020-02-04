#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  cin >> n;

  unordered_map<int, unordered_map<int, int>> last;
  string s;
  cin >> s;
  int x = 0, y = 0;
  last[0][0] = 1;
  const int INF = 1e9;
  int d = INF;
  pair<int, int> ans;
  rep(i, n) {
    switch (s[i]) {
      case 'L':
        x -= 1;
        break;
      case 'R':
        x += 1;
        break;
      case 'U':
        y += 1;
        break;
      case 'D':
        y -= 1;
        break;
    }
    if (last[x][y] && chmin(d, i + 2 - last[x][y]))
      ans = make_pair(last[x][y], i + 1);
    last[x][y] = i + 2;
  }

  if (d == INF) {
    cout << -1 << endl;
  } else {
    cout << ans.first << " " << ans.second << endl;
  }
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
