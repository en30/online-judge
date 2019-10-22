#include <bits/stdc++.h>
#include "../include/template"

const int INF = 1e9 + 1;
int N;
vector<int> h, dp;

int main() {
  cin >> N;
  h.resize(N), dp.resize(N, INF);
  rep(i, N) cin >> h[i];

  dp[0] = 0;

  rep(i, N - 1) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
    if (i + 2 < N) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
  }

  cout << dp[N - 1] << endl;

  return 0;
}
