#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;

  using p = pair<int, int>;
  vector<p> v(N + M);
  rep(i, N) {
    cin >> v[i].first;
    v[i].second = 1;
  }
  rep(i, M) { cin >> v[i + N].second >> v[i + N].first; }

  sort(v.rbegin(), v.rend());

  int n = N;
  ll ans = 0;
  rep(i, N + M) {
    ll k = min(v[i].second, n);
    ans += v[i].first * k;
    n -= k;
    if (n == 0) break;
  }

  cout << ans << endl;
  return 0;
}
