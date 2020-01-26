#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  rep(i, N) cin >> H[i];

  sort(all(H));

  ll ans = 0;
  rep(i, N - K) ans += H[i];

  cout << ans << endl;

  return 0;
}
