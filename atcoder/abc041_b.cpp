#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<ll> R(3);
  rep(i, 3) cin >> R[i];

  ll ans = 1;
  rep(i, 3) {
    ans *= R[i];
    ans %= 1000000007;
  }

  cout << ans << endl;
  return 0;
}
