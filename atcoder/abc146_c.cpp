#include <bits/stdc++.h>
#include "../include/template"

ll A, B, X;

ll d(ll n) {
  if (n == 0) return 0;
  return d(n / 10) + 1;
}

int main() {
  cin >> A >> B >> X;

  ll l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    ll m = (r + l) / 2;
    if (X >= A * m + B * d(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l << endl;
  return 0;
}
