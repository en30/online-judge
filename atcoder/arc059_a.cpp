#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  double m = 0;
  rep(i, N) m += a[i];
  m /= N;

  auto cost = [&](int k) {
    ll res = 0;
    rep(i, N) res += (k - a[i]) * (k - a[i]);
    return res;
  };

  int f = floor(m), c = ceil(m);
  cout << min(cost(f), cost(c)) << endl;

  return 0;
}
