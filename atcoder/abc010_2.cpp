#include <bits/stdc++.h>
#include "../include/template"

int n;

int main() {
  cin >> n;

  int ans = 0;
  rep(i, n) {
    int a;
    cin >> a;
    while ((a % 2) == 0 || (a % 3 == 2)) {
      --a;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
