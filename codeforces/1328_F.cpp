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

  const ll INF = 1e18;

  auto pushDownCost = [&](ll m) -> ll {
    int c = 0;
    ll res = k - hist[m];
    rep(i, n) {
      c += (a[i] >= m);
      res += max(a[i] - m + 1, 0LL);
    }
    return c >= k ? res : INF + m;
  };
  auto pushUpCost = [&](ll m) -> ll {
    int c = 0;
    ll res = k - hist[m];
    rep(i, n) {
      c += (a[i] <= m);
      res += max(m - 1 - a[i], 0LL);
    }
    return c >= k ? res : INF - m;
  };
  auto sandCost = [&](ll m) -> ll {
    ll res = k - hist[m];
    rep(i, n) {
      res += max(a[i] - (m + 1), 0LL);
      res += max(m - 1 - a[i], 0LL);
    }
    return res;
  };
  ll ans = 1e18;
  chmin(ans, minimal<ll>(pushDownCost, 0, 1e9 + 1));
  chmin(ans, minimal<ll>(pushUpCost, 0, 1e9 + 1));
  chmin(ans, minimal<ll>(sandCost, 0, 1e9 + 1));

  cout << ans << endl;

  return 0;
}
