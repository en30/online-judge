#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<ll> A;

int main() {
  cin >> N;
  A.resize(N);
  rep(i, N) cin >> A[i];

  vector<ll> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + A[i];

  ll ans = 1e18;
  rep(i, N - 1) {
    ll l = S[i + 1], r = S[N] - S[i + 1];
    ans = min(ans, abs(l - r));
  }

  cout << ans << endl;

  return 0;
}
