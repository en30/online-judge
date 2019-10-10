#include <bits/stdc++.h>
#include "../include/template"

ll x;
int main() {
  cin >> x;

  ll ans = (x / 11) * 2;
  ans += (x % 11 == 0 ? 0 : (x % 11 <= 6 ? 1 : 2));

  cout << ans << endl;
  return 0;
}
