#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int n;
int main() {
  ModInt::mod(10007);

  cin >> n;
  vector<ModInt> a(n, 0);
  a[2] = 1;
  rep(i, n - 3) a[i + 3] = a[i] + a[i + 1] + a[i + 2];

  cout << a[n - 1] << endl;
  return 0;
}
