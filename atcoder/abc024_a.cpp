#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B, K, C, S, T;
  cin >> A >> B >> C >> K >> S >> T;
  int ans = A * S + B * T;
  if (S + T >= K) ans -= C * (S + T);
  cout << ans << endl;
  return 0;
}
