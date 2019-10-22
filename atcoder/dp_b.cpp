#include <bits/stdc++.h>
#include "../include/template"

const int INF = 1e9 + 1;
int N, K;
vector<int> h, dp;

int main() {
  cin >> N >> K;
  h.resize(N), dp.resize(N, INF);
  rep(i, N) cin >> h[i];

  dp[0] = 0;

  rep(i, N) {
    rep(j, K) {
      if (i + 1 + j < N)
        dp[i + 1 + j] = min(dp[i + 1 + j], dp[i] + abs(h[i + 1 + j] - h[i]));
    }
  }

  cout << dp[N - 1] << endl;

  return 0;
}
