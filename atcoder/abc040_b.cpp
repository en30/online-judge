#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    int j = n / i;
    int r = n - i * j;
    chmin(ans, abs(i - j) + r);
  }
  cout << ans << endl;
  return 0;
}
