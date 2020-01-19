#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  vector<int> P(N);
  rep(i, N) cin >> P[i];

  int m = 1e9;
  int ans = 0;
  rep(i, N) {
    if (P[i] <= m) ++ans;
    m = min(m, P[i]);
  }

  cout << ans << endl;

  return 0;
}
