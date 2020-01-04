#include <bits/stdc++.h>
#include "../include/template"

const int INF = 1e9;
int N;
int main() {
  cin >> N;
  vector<int> ng(3);
  rep(i, 3) cin >> ng[i];

  auto isNg = [&](int n) { return find(ng.begin(), ng.end(), n) != ng.end(); };
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  rep(i, N) {
    if (i + 1 <= N && !isNg(i + 1)) dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
    if (i + 2 <= N && !isNg(i + 2)) dp[i + 2] = min(dp[i + 2], 1 + dp[i]);
    if (i + 3 <= N && !isNg(i + 3)) dp[i + 3] = min(dp[i + 3], 1 + dp[i]);
  }

  cout << (dp[N] <= 100 ? "YES" : "NO") << endl;

  return 0;
}
