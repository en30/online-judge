#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;
  int ans = 0;
  rep(i, N) {
    int l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }

  cout << ans << endl;
  return 0;
}
