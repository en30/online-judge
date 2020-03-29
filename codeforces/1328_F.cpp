#include <bits/stdc++.h>
#include "../include/template"
#include "../include/ternary_search.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  map<int, ll> hist;
  rep(i, n) {
    scanf("%lld", &a[i]);
    ++hist[a[i]];
  }

  for (auto& p : hist) {
    if (p.second >= k) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1e18;
  {
    auto achievable = [&](int m) {
      int c = 0;
      rep(i, n) c += (a[i] >= m);
      return c >= k;
    };
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (achievable(m)) {
        l = m;
      } else {
        r = m;
      }
    }

    ll res = 0;
    rep(i, n) res += max(a[i] - (l + 1), 0LL);
    res += k - hist[l];
    chmin(ans, res);
  }
  {
    auto achievable = [&](int m) {
      int c = 0;
      rep(i, n) c += (a[i] <= m);
      return c >= k;
    };
    int l = 0, r = 1e9;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (achievable(m)) {
        r = m;
      } else {
        l = m;
      }
    }

    ll res = 0;
    rep(i, n) res += max(r - 1 - a[i], 0LL);
    res += k - hist[r];
    chmin(ans, res);
  }
  {
    auto cost = [&](int m) {
      ll c = 0;
      rep(i, n) {
        if (a[i] == m) continue;
        c += max(a[i] - (m + 1), 0LL);
        c += max(m - 1 - a[i], 0LL);
      }
      c += k - hist[m];
      return c;
    };
    auto negativeGradient = [&](int m) { return cost(m + 1) - cost(m) < 0; };
    int l = 0, r = 1e9;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (negativeGradient(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    chmin(ans, cost(r));
  }

  cout << ans << endl;

  return 0;
}
