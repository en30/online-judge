#include <bits/stdc++.h>
#include "../include/template"
#include "../include/gcd.hpp"

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  int m = lcm(a, b);
  cout << m * ((n + m - 1) / m) << endl;
  return 0;
}
