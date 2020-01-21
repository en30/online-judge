#include <bits/stdc++.h>
#include "../include/template"

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + b + c - max({a,b,c}) - min({a,b,c})) << endl;
  return 0;
}
