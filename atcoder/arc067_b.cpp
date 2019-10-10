#include <bits/stdc++.h>
#include "../include/template"

ll N, A, B;
vector<ll> X;
int main() {
  cin >> N >> A >> B;
  X.resize(N);

  rep(i, N) cin >> X[i];

  ll ans = 0;
  rep(i, N - 1) ans += min((X[i + 1] - X[i]) * A, B);

  cout << ans << endl;
  return 0;
}
