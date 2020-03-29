#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", (a % b ? b - a % b : 0));
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();

  return 0;
}
