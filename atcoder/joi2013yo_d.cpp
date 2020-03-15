#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int D, N;
  cin >> D >> N;
  vector<int> T(D);
  rep(i, D) cin >> T[i];
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i] >> B[i] >> C[i];

  auto good = [&](int d, int i) { return A[i] <= T[d] && T[d] <= B[i]; };
  vector<vector<int>> dp(D, vector<int>(N, 0));
  for (int d = 1; d < D; ++d) rep(j, N) rep(k, N) {
      if (!good(d, j) || !good(d - 1, k)) continue;
      chmax(dp[d][j], dp[d - 1][k] + abs(C[j] - C[k]));
    }

  cout << *max_element(all(dp[D - 1])) << endl;

  return 0;
}
