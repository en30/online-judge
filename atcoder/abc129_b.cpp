#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  vector<int> W(N);
  rep(i, N) cin >> W[i];

  int ans = 1e9;
  vector<int> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + W[i];
  rep(i, N - 1) ans = min(ans, abs(2 * S[i + 1] - S[N]));
  cout << ans << endl;
  return 0;
}
