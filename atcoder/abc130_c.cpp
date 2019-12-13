#include <bits/stdc++.h>
#include "../include/template"

int W, H, x, y;

int main() {
  cin >> W >> H >> x >> y;

  double d = double(W) * H * 0.5;
  cout << setprecision(10) << d;
  cout << " " << (2 * x == W && 2 * y == H) << endl;
  return 0;
}
