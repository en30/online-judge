#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  int ans = -1e9;
  rep(i, N) {
    int ma = -1e9, t;
    rep(j, N) {
      if (j == i) continue;

      int l = min(i, j), r = max(i, j), st = 0, sa = 0;
      for (int k = l; k <= r; ++k) {
        if ((k - l) % 2) {
          sa += a[k];
        } else {
          st += a[k];
        }
      }
      if (chmax(ma, sa)) t = st;
    }
    chmax(ans, t);
  }

  cout << ans << endl;

  return 0;
}
