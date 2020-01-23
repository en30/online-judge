#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) rep(j, m) cin >> a[i][j];

  int ans = 0;
  rep(c, m) {
    vector<int> hist(n, 0);

    auto dist = [&](int r, int k) {
      if (k < 1 || k > n * m || (k - 1) % m != c) return -1;
      int d = r - ((k - 1) / m);
      if (d < 0) d += n;
      return d;
    };

    rep(r, n) {
      int d = dist(r, a[r][c]);
      if (d == -1) continue;
      hist[d] += 1;
    }

    int curr = 1e9;
    rep(i, n) chmin(curr, i + (n - hist[i]));
    ans += curr;
  }

  cout << ans << endl;

  return 0;
}
