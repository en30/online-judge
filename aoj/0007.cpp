#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int n;
  cin >> n;
  double x = 1e2;
  rep(i, n) x = ceil(x * 1.05);
  cout << ll(x * 1000) << endl;

  return 0;
}
