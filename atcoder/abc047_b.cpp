#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  int l = 0, r = W, b = 0, t = H;
  rep(i, N) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      chmax(l, x);
    } else if (a == 2) {
      chmin(r, x);
    } else if (a == 3) {
      chmax(b, y);
    } else {
      chmin(t, y);
    }
  }

  cout << max(0, r - l) * max(0, t - b) << endl;

  return 0;
}
