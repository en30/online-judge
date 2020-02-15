#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N), c(N + 1, 0);
  rep(i, N) cin >> a[i];
  for (int i = 0; i < N - K + 1; ++i) {
    c[i] += 1;
    c[i + K] -= 1;
  }
  rep(i, N) c[i + 1] += c[i];
  ll ans = 0;
  rep(i, N) ans += a[i] * c[i];
  cout << ans << endl;

  return 0;
}
