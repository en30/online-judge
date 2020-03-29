#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  ll n, k;
  scanf("%lld %lld", &n, &k);

  ll sum = 0;
  int l = n - 2;
  while (sum + (n - 1 - l) < k) {
    sum += n - 1 - l;
    --l;
  }
  int r = n - 1 - (k - sum - 1);
  rep(i, n) printf("%c", (i == l || i == r ? 'b' : 'a'));
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
