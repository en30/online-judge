#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A;
  cin >> A;
  int ans = 0;
  for (int i = 1; i < A; ++i) {
    chmax(ans, i * (A - i));
  }

  cout << ans << endl;
  return 0;
}
