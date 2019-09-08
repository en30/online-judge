#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> P;

int main() {
  cin >> N;
  P.resize(N);
  rep(i, N) cin >> P[i];

  ll ans = 0;
  vector<int> idx(N + 1);
  rep(i, N) idx[P[i]] = i;

  multiset<int> s;
  rep(i, 2) s.insert(-1);
  rep(i, 2) s.insert(N);

  for (int i = N; i >= 1; --i) {
    int j = idx[i];
    auto it = s.lower_bound(j);
    int r1 = *it, r2 = *next(it), l1 = *prev(it), l2 = *prev(prev(it));
    ans += ll(i) * ((r2 - r1) * (j - l1) + (l1 - l2) * (r1 - j));
    s.insert(j);
  }

  cout << ans << endl;

  return 0;
}
