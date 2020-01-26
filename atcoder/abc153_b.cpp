#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll H, N;
  cin >> H >> N;
  rep(i, N) {
    int A;
    cin >> A;
    H -= A;
  }

  cout << (H <= 0 ? "Yes" : "No") << endl;

  return 0;
}
