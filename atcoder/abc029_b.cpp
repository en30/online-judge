#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  int ans = 0;
  rep(i, 12) {
    cin >> S;
    ans += (count(all(S), 'r') != 0);
  }
  cout << ans << endl;
  return 0;
}
