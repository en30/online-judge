#include <bits/stdc++.h>
#include "../include/template"
#include "../include/cumulative_sum.hpp"

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  CumulativeSum<ll> S(a);
  ll ans = 0;
  for (int i = 0; i + K <= N; ++i) {
    ans += S.query(i, i + K);
  }
  cout << ans << endl;

  return 0;
}
