#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> hate(10, false);
  rep(i, K) {
    int D;
    cin >> D;
    hate[D] = true;
  }

  function<bool(int)> ok = [&](int n) {
    if (n == 0) return true;
    if (hate[n % 10]) return false;
    return ok(n / 10);
  };

  for (int i = N;; ++i) {
    if (ok(i)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
