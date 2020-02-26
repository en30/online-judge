#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> lindex(10, N - 1), rindex(10, 0);
  vector<vector<int>> T(N + 1, vector<int>(10, 0));
  rep(i, N) {
    int s = S[i] - '0';
    chmin(lindex[s], i);
    chmax(rindex[s], i);
    rep(j, 10) T[i + 1][j] = T[i][j] + (j == s);
  }

  int ans = 0;
  rep(l, 10) rep(r, 10) rep(k, 10) {
    ans += (T[rindex[r]][k] - T[lindex[l] + 1][k] > 0);
  }

  cout << ans << endl;

  return 0;
}
