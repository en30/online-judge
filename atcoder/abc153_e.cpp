#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  vector<ll> dp(H + 1, 1e18);
  dp[0] = 0;

  rep(i, N) rep(j, H + 1) chmin(dp[min(j + A[i], H)], dp[j] + B[i]);

  cout << dp[H] << endl;
  return 0;
}
