#include <bits/stdc++.h>
#include "../include/template"

int t;

void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  vector<ll> S(n + 1, 0);
  rep(i, n) S[i + 1] = S[i] + a[i];
  vector<vector<ll>> T(k, vector<ll>(n / k + 10, 0));
  rep(i, k) for (ll j = 0; i + j * k < n; ++j) {
    T[i][j + 1] = T[i][j] + a[i + j * k];
  }

  auto ok = [&](int i, ll j) {
    if (i + j * k > n) return false;
    int d = (i - 1 + k) % k;

    return S[i] + T[d][(i - 1 + j * k) / k + 1] - T[d][(i - 1 + k) / k] <= p;
  };

  int ans = 0;
  rep(i, n + 1) {
    if (p - S[i] < 0) break;

    int l = 0, r = 1e6;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (ok(i, m)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans = max(ans, i + l * k);
  }

  cout << ans << endl;
}

int main() {
  cin >> t;
  rep(i, t) solve();
  return 0;
}
