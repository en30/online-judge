#include <bits/stdc++.h>
#include "../include/template"

int t;

void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  vector<ll> dp(n + 1, 0);
  rep(i, n) {
    if (i < k - 1) {
      dp[i + 1] = dp[i] + a[i];
    } else {
      dp[i + 1] = min(dp[i], dp[i - k + 1]) + a[i];
    }
  }

  for (int i = n; i >= 0; --i) {
    if (dp[i] > p) continue;
    cout << i << endl;
    return;
  }
}

int main() {
  cin >> t;
  rep(i, t) solve();
  return 0;
}
