#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<vector<int>> h, dp;

int main() {
  cin >> N;

  h.resize(N, vector<int>(3));
  rep(i, N) rep(j, 3) { cin >> h[i][j]; }

  dp.resize(2, vector<int>(3, 0));

  rep(i, N) {
    rep(j, 3) {
      rep(k, 3) {
        if (j == k) continue;

        dp[(i + 1) & 1][k] = max(dp[(i + 1) & 1][k], dp[i & 1][j] + h[i][k]);
      }
    }
  }

  cout << *max_element(all(dp[N & 1])) << endl;

  return 0;
}
