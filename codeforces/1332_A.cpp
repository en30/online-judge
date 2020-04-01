#include <bits/stdc++.h>
#include "../include/template"

bool solve() {
  int l, r, d, u;
  scanf("%d %d %d %d", &l, &r, &d, &u);
  int x, y, x1, y1, x2, y2;
  scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);

  if (x1 == x2 && (l != 0 || r != 0)) return false;
  if (y1 == y2 && (u != 0 || d != 0)) return false;
  if (r > l && r - (x2 - x) - l > 0) return false;
  if (l > r && l - (x - x1) - r > 0) return false;
  if (u > d && u - (y2 - y) - d > 0) return false;
  if (d > u && d - (y - y1) - u > 0) return false;
  return true;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}
