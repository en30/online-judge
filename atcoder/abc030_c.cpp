#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, M;
  cin >> N >> M;
  int X, Y;
  cin >> X >> Y;
  vector<int> a(N), b(M);
  rep(i, N) cin >> a[i];
  rep(i, M) cin >> b[i];

  ll t = 0, ans = 0;
  while (true) {
    auto it = lower_bound(all(a), t);
    if (it == a.end()) break;
    t = (*it) + X;
    it = lower_bound(all(b), t);
    if (it == b.end()) break;
    t = (*it) + Y;
    ++ans;
  }

  cout << ans << endl;

  return 0;
}
