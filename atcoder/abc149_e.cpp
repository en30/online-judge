#include <bits/stdc++.h>
#include "../include/template"

ll N;
ll M;
vector<ll> A;

int main() {
  cin >> N >> M;
  A.resize(N);
  rep(i, N) cin >> A[i];

  sort(all(A));

  vector<ll> S(N + 1, 0);
  rep(i, N) S[i + 1] = S[i] + A[i];

  function<ll(ll)> num = [&](ll t) {
    ll res = 0;
    rep(i, N) res += distance(lower_bound(all(A), t - A[i]), A.end());
    return res;
  };

  ll l = 0, r = 1e6;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (num(m) <= M) {
      r = m;
    } else {
      l = m;
    }
  }

  ll ans = 0;
  ll rest = M;
  rep(i, N) {
    int l = distance(lower_bound(all(A), r - A[i]), A.end());
    ans += l * A[i] + S[N] - S[N - l];
    rest -= l;
  }
  ans += rest * l;

  cout << ans << endl;

  return 0;
}
