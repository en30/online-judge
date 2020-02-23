#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ll N;
  cin >> N;

  vector<int> d;
  for (ll m = N; m != 0; m /= 2) {
    d.push_back(m % 2);
  }
  reverse(all(d));

  const int D = d.size();
  vector<vector<ModInt>> dp(D + 1, vector<ModInt>(3, 0));
  dp[0][0] = 1;

  rep(i, D) rep(j, 3) rep(ab, 3) {
    // ab: (0, 0), (0, 1), (1, 1)
    int delta = j * 2 + d[i] - ab;
    if (delta >= 0) dp[i + 1][min(2, delta)] += dp[i][j];
  }

  cout << accumulate(all(dp[D]), ModInt(0)) << endl;

  return 0;
}
