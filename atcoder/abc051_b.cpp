#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int K, S;
  cin >> K >> S;

  int ans = 0;
  rep(X, K + 1) rep(Y, K + 1) {
    int Z = S - X - Y;
    if (0 <= Z && Z <= K) ++ans;
  }

  cout << ans << endl;
  return 0;
}
