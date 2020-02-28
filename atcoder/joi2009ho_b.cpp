#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int l;
  cin >> l;
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<int> d(n + 1, 0);
  rep(i, n - 1) cin >> d[i + 1];
  d[n] = l;

  sort(all(d));
  int ans = 0;
  rep(i, m) {
    int k;
    cin >> k;
    auto it = lower_bound(all(d), k);
    if (it == d.begin()) continue;
    ans += min(*it - k, k - *prev(it));
  }

  cout << ans << endl;

  return 0;
}
