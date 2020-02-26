#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) rep(j, M) cin >> A[i][j];

  ll ans = 0;
  rep(t1, M) for (int t2 = t1 + 1; t2 < M; ++t2) {
    ll s = 0;
    rep(i, N) s += max(A[i][t1], A[i][t2]);
    chmax(ans, s);
  }
  cout << ans << endl;
  return 0;
}
