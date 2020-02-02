#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  int ans = 0, m = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if (a > m) ++ans;
    chmax(m, a);
  }

  cout << ans << endl;

  return 0;
}
