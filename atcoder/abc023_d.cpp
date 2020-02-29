#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<ll> H(N), S(N);
  rep(i, N) cin >> H[i] >> S[i];

  auto achievable = [&](ll x) {
    vector<int> c(N, 0);
    rep(i, N) {
      if (x - H[i] < 0) return false;
      ll t = (x - H[i]) / S[i];
      chmin(t, ll(N - 1));
      ++c[t];
    }
    vector<ll> s(N + 1, 0);
    rep(i, N) s[i + 1] = s[i] + c[i];
    rep(i, N) if (s[i + 1] > i + 1) return false;
    return true;
  };

  ll l = 0, r = 1e18;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (achievable(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << endl;

  return 0;
}
