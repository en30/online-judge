#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  scanf("%d", &n);

  set<int> s;
  rep(i, n) {
    int a;
    scanf("%d", &a);
    s.insert(a);
  }

  printf("%d\n", s.size());
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
