#include <bits/stdc++.h>
#include "../include/template"

int M, K;

int main() {
  cin >> M >> K;

  int N = (1 << M);

  if ((M < 2 && K != 0) || K >= N) {
    cout << -1 << endl;
    return 0;
  }

  if (M < 2) {
    rep(i, N) {
      if (i != 0) cout << " ";
      cout << i << " " << i;
    }
    cout << endl;
    return 0;
  }

  bool first = true;
  rep(i, N) {
    if (i == K) continue;
    if (!first) cout << " ";
    first = false;
    cout << i;
  }
  cout << " " << K;
  for (int i = N - 1; i >= 0; --i) {
    if (i == K) continue;
    cout << " " << i;
  }
  cout << " " << K << endl;

  return 0;
}
