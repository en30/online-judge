#include <bits/stdc++.h>
#include "../include/template"

int H, W, A, B;

int main() {
  cin >> H >> W >> A >> B;

  rep(i, H) {
    rep(j, W) cout << !((i < B) ^ (j < A));
    cout << endl;
  }
  return 0;
}
