#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;

  vector<int> h(n), c(n);
  rep(i, n) {
    cin >> h[i];
    int d = (h[i] % (a + b));
    if (d == 0) d = a + b;
    c[i] = (d - 1) / a;
  }
  sort(all(c));

  int ans = 0;
  rep(i, n) {
    if (c[i] > k) break;
    k -= c[i];
    ++ans;
  }
  cout << ans << endl;

  return 0;
}
