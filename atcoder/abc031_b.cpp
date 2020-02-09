#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int L, H;
  cin >> L >> H;
  int N;
  cin >> N;
  rep(i, N) {
    int A;
    cin >> A;
    if (A > H) {
      cout << -1 << endl;
    } else {
      cout << max(0, L - A) << endl;
    }
  }
  return 0;
}
