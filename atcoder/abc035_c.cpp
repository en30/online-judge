#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> o(N + 1, 0);
  rep(i, Q) {
    int l, r;
    cin >> l >> r;
    o[l - 1] ^= 1;
    o[r] ^= 1;
  }
  rep(i, N) o[i + 1] ^= o[i];
  rep(i, N) cout << o[i];
  cout << endl;
  return 0;
}
