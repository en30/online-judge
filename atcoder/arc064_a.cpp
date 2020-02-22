#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  ll ans = 0;
  rep(i, N - 1) {
    int c = a[i] + a[i + 1] - x;
    if (c > 0) {
      a[i + 1] = max(0, a[i + 1] - c);
      ans += c;
    }
  }

  cout << ans << endl;

  return 0;
}
