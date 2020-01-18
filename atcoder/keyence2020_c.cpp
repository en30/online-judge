#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K, S;
  cin >> N >> K >> S;

  bool printed = false;
  rep(i, K) {
    if (printed) cout << " ";
    cout << S;
    printed = true;
  }

  rep(i, N - K) {
    if (printed) cout << " ";
    cout << (S == 1000000000 ? 1 : S + 1);
    printed = true;
  }
  return 0;
}
