#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  ModInt A, B, C;
  cin >> A >> B >> C;

  ModInt r, c;

  r = C * (B - A) / (A * B - C * B + C * A);
  c = B * (C - A) / (A * C - C * B + B * A);
  cout << r << " " << c << endl;

  return 0;
}
