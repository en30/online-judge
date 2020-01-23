#include <bits/stdc++.h>
#include "../include/template"

struct Package {
  int x, y;
};

void solve() {
  int n;
  cin >> n;
  vector<Package> p(n);
  rep(i, n) cin >> p[i].x >> p[i].y;

  sort(all(p), [&](const Package& a, const Package& b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });

  string path = "";
  int x = 0, y = 0;
  rep(i, n) {
    path += string(p[i].x - x, 'R');
    x = p[i].x;
    if (p[i].y < y) {
      cout << "NO" << endl;
      return;
    }
    path += string(p[i].y - y, 'U');
    y = p[i].y;
  }
  cout << "YES" << endl;
  cout << path << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
