#include <bits/stdc++.h>
#include "../include/template"

int H, W, N;
int main() {
  cin >> H >> W >> N;
  if (H < W) swap(H, W);

  cout << (N + H - 1) / H << endl;

  return 0;
}
