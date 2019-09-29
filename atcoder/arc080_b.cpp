#include <bits/stdc++.h>
#include "../include/template"

int H, W, N;
vector<vector<int>> ans;

struct elem {
  int n, v;
  elem(int n, int v) : n(n), v(v){};
};
vector<elem> b;

int main() {
  cin >> H >> W >> N;
  ans.resize(H, vector<int>(W, 0));
  rep(i, N) {
    int a;
    cin >> a;
    b.emplace_back(a, i + 1);
  }

  int k = 0;
  rep(i, H) rep(j, W) {
    int y = i;
    int x = (i % 2 == 0 ? j : W - 1 - j);
    if (b[k].n == 0) k++;
    ans[y][x] = b[k].v;
    b[k].n--;
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
