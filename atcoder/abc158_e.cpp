#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  reverse(all(S));
  if (P == 2 || P == 5) {
    ll ans = 0;
    rep(i, N) if ((S[i] - '0') % P == 0) ans += N - i;
    cout << ans << endl;
    return 0;
  }

  vector<ll> T(N + 1, 0);
  ll r = 1;
  rep(i, N) {
    T[i + 1] = T[i] + r * (S[i] - '0');
    T[i + 1] %= P;
    r *= 10;
    r %= P;
  }

  ll ans = 0;
  map<ll, ll> C;
  rep(i, N + 1) {
    ans += C[T[i]];
    ++C[T[i]];
  }
  cout << ans << endl;

  return 0;
}
