#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), a(n, 0), b(n, 0);
  rep(i, n) {
    char c;
    cin >> c;
    x[i] = (c - '0');
  }

  bool found = false;
  rep(i, n) {
    if (found) {
      a[i] = 0;
      b[i] = x[i];
      continue;
    }
    if (x[i] == 2) {
      a[i] = 1;
      b[i] = 1;
    } else if (x[i] == 0) {
      a[i] = 0;
      b[i] = 0;
    } else if (x[i] == 1) {
      a[i] = 1;
      b[i] = 0;
      found = true;
    }
  }

  rep(i, n) printf("%d", a[i]);
  printf("\n");
  rep(i, n) printf("%d", b[i]);
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}
