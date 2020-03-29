#include <bits/stdc++.h>
#include "../include/template"
#include "../include/binary_search.hpp"
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
  ll ans = 1e18;

  ll u = integer_partition_point<ll>(0, 1e9 + 1, [&](ll m) {
    int c = count_if(all(a), [&](int v) { return v >= m; });
    return c >= k;
  });
  chmin(ans, accumulate(all(a), k - hist[u],
                        [&](ll a, ll e) { return a + max(e - (u + 1), 0LL); }));

  ll d = integer_partition_point<ll>(0, 1e9 + 1, [&](ll m) {
    int c = count_if(all(a), [&](int v) { return v <= m; });
    return c < k;
  });
  ++d;
  chmin(ans, accumulate(all(a), k - hist[d],
                        [&](ll a, ll e) { return a + max(d - 1 - e, 0LL); }));

  auto sandCost = [&](ll m) -> ll {
    return accumulate(all(a), k - hist[m], [&](ll a, ll e) {
      a += max(e - (m + 1), 0LL);
      a += max(m - 1 - e, 0LL);
      return a;
    });
  };

  chmin(ans, minimal<ll>(sandCost, 0, 1e9 + 1));

  cout << ans << endl;

  return 0;
}
