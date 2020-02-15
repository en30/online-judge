#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  ll ans = 0;
  ll l = 0, r = 0;
  while (l < N) {
    while (r + 1 < N && a[r + 1] > a[r]) ++r;
    ans += (r - l + 2) * (r - l + 1) / 2;
    l = r + 1;
    r = l;
  }

  cout << ans << endl;

  return 0;
}
