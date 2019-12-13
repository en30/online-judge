#include <bits/stdc++.h>
#include "../include/template"

ll N, K;
vector<ll> a;
int main() {
  cin >> N >> K;
  a.resize(N);
  rep(i, N) cin >> a[i];

  vector<ll> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + a[i];

  ll ans = 0;
  rep(i, N) {
    int k = distance(S.begin(), lower_bound(S.begin() + i, S.end(), K + S[i]));
    ans += N - k + 1;
  }

  cout << ans << endl;
  return 0;
}
