#include <bits/stdc++.h>
#include "../include/template"

int N, T;

struct Food {
  int t, d;
};

vector<Food> F;

int main() {
  cin >> N >> T;
  F.resize(N);
  rep(i, N) cin >> F[i].t >> F[i].d;

  sort(all(F), [&](const Food& a, const Food& b) { return a.t < b.t; });
  assert(F[0].t <= F[N - 1].t);

  vector<vector<int>> dp(N + 1, vector<int>(T, 0));
  rep(i, N) rep(t, T) {
    dp[i + 1][t] = dp[i][t];
    if (t - F[i].t >= 0)
      dp[i + 1][t] = max(dp[i + 1][t], dp[i][t - F[i].t] + F[i].d);
  }

  int ans = 0;
  rep(i, N) rep(t, T) ans = max(ans, dp[i][t] + F[i].d);

  cout << ans << endl;
  return 0;
}
