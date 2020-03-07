#include <bits/stdc++.h>
#include "../include/template"

struct Size {
  int r, c;
};

int main() {
  int n;
  cin >> n;
  vector<Size> M(n);
  rep(i, n) cin >> M[i].r >> M[i].c;

  const int INF = 1e9;

  vector<vector<int>> dp(n, vector<int>(n, INF));
  rep(i, n) dp[i][i] = 0;

  function<int(int, int)> f = [&](int l, int r) {
    if (dp[l][r] != INF) return dp[l][r];

    int res = INF;
    for (int k = l; k < r; ++k) {
      chmin(res, f(l, k) + f(k + 1, r) + M[l].r * M[k].c * M[r].c);
    }
    return dp[l][r] = res;
  };

  cout << f(0, n - 1) << endl;

  return 0;
}
