#include <bits/stdc++.h>
#include "../include/template"

ll f(ll n) {
  if (n == 1LL) return 1LL;
  return memo[n] = 1LL + 2LL * f(n / 2LL);
}

int main() {
  ll H;
  cin >> H;

  cout << f(H) << endl;
  return 0;
}
