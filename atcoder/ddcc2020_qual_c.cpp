#include <bits/stdc++.h>
#include "../include/template"

int H, W, K;
vector<vector<char>> s;
vector<vector<int>> ans;

int main() {
  cin >> H >> W >> K;

  s.resize(H, vector<char>(W));
  ans.resize(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> s[i][j];

  int k = 1, y = 0;
  rep(i, H) {
    int c = 0, x = 0;
    rep(j, W) {
      if (s[i][j] == '#') {
        ++c;
        if (c > 1) {
          for (int l = y; l <= i; ++l) {
            for (int m = x; m < j; ++m) {
              ans[l][m] = k;
            }
          }
          ++k;
          x = j;
        }
      }
    }
    if (c != 0) {
      for (int l = y; l <= i; ++l) {
        for (int m = x; m < W; ++m) {
          ans[l][m] = k;
        }
      }

      ++k;
      y = i + 1;
    }
  }
  assert(k == K + 1);

  rep(j, W) {
    int m = 0;
    rep(i, H) {
      m = max(m, ans[i][j]);
      if (ans[i][j] == 0) ans[i][j] = m;
    }
  }

  rep(i, H) {
    rep(j, W) {
      if (j != 0) cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
