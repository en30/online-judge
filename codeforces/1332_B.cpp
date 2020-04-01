#include <bits/stdc++.h>
#include "../include/template"

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  rep(i, n) scanf("%d", &a[i]);

  vector<int> ans(n, -1);

  int c = 0;
  auto isPrime = [](int n) {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  };
  for (int i = 2; i * i <= 1000; ++i) {
    if (isPrime(i)) {
      bool used = false;
      rep(j, n) if (a[j] % i == 0 && ans[j] == -1) {
        ans[j] = c;
        used = true;
      }
      if (used) ++c;
    }
  }

  printf("%d\n", c);
  rep(i, n) {
    if (i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
}

int main() {
  int t;
  cin >> t;
  rep(i, t) solve();

  return 0;
}
