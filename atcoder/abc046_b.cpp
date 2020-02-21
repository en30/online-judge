#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  int ans = K;
  rep(i, N - 1) ans *= (K - 1);
  cout << ans << endl;
  return 0;
}
