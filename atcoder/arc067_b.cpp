#include <bits/stdc++.h>
#include "../include/template"

ll N, A, B;
vector<ll> X;
int main() {
  cin >> N >> A >> B;
  X.resize(N);

  rep(i, N) cin >> X[i];

  int M = N - 1;
  ll ans = 0;
  rep(i, N - 1) {
    ll c = (X[i + 1] - X[i]) * A;
    if (c <= B) {
      --M;
      ans += c;
    }
  }
  ans += M * B;

  cout << ans << endl;
  return 0;
}
