#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), c(m, 0);
  rep(i, n) {
    cin >> a[i];
    ++c[a[i] % m];
  }

  rep(i, m) {
    if (c[i] > 1) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 1;
  sort(a.rbegin(), a.rend());
  rep(i, n) for (int j = i + 1; j < n; ++j) {
    ans *= (a[i] - a[j]) % m;
    ans %= m;
  }
  cout << ans << endl;

  return 0;
}
