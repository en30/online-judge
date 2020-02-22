#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  cout << b / x - (a == 0 ? -1 : (a - 1) / x) << endl;
  return 0;
}
