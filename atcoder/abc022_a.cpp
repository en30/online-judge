#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, S, T, W;
  cin >> N >> S >> T >> W;

  int ans = 0;
  rep(i, N) {
    if (i != 0) {
      int A;
      cin >> A;
      W += A;
    }
    ans += (S <= W && W <= T);
  }

  cout << ans << endl;
  return 0;
}
