#include <bits/stdc++.h>
#include "../include/template"
#include "../include/cumulative_sum_2d.hpp"

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<int>> S(H, vector<int>(W));
  rep(i, H) rep(j, W) {
    char c;
    cin >> c;
    S[i][j] = (c == '1');
  }

  CumulativeSum2D<int> cum(S);

  int ans = 1e9;
  rep(s, 1 << (H - 1)) {
    int cost = 0;
    vector<int> y;
    y.push_back(0);
    rep(i, H - 1) if ((s >> i) & 1) {
      y.push_back(i + 1);
      ++cost;
    }
    y.push_back(H);

    int Y = y.size();
    int l = 0;
    for (int r = 1; r <= W;) {
      bool ok = true;
      rep(j, Y - 1) ok &= (cum.query(y[j], l, y[j + 1], r) <= K);
      if (!ok) {
        if (r == l + 1) goto HOGE;
        ++cost;
        l = r - 1;
      } else {
        ++r;
      }
    }
    chmin(ans, cost);
  HOGE:;
  }

  cout << ans << endl;

  return 0;
}
