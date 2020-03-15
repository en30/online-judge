#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll H, W;
  cin >> H >> W;

  cout << (H == 1 || W == 1 ? 1 : (H * W + 1) / 2) << endl;

  return 0;
}
