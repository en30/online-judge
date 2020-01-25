#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll N, T;
  cin >> N >> T;
  ll ans = 0;
  ll l = 0, r = 0;
  rep(i, N) {
    int A;
    cin >> A;
    if (r < A) {
      ans += (r - l);
      l = A;
    }
    r = A + T;
  }
  ans += r - l;

  cout << ans << endl;

  return 0;
}
