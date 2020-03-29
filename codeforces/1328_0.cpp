#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", ((a + b - 1) / b) * b - a);
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();

  return 0;
}
