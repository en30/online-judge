#include <bits/stdc++.h>
#include "../include/template"

struct Balloon {
  ll H, S;
};

int main() {
  int N;
  cin >> N;
  vector<Balloon> B(N);
  rep(i, N) cin >> B[i].H >> B[i].S;

  auto achievable = [&](ll s) {
    vector<ll> ts(N);
    rep(i, N) ts[i] = (s - B[i].H) / B[i].S;
    sort(ts.rbegin(), ts.rend());
    rep(i, N) if (ts[i] < N - 1 - i) return false;
    return true;
  };

  ll l = 0, r = 1e18;
  while (r - l > 1LL) {
    ll m = (l + r) / 2LL;
    if (achievable(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << r << endl;

  return 0;
}
