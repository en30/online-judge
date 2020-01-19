#include <bits/stdc++.h>
#include "../include/template"

int a, b;

int main() {
  cin >> a >> b;
  string s(b, '0' + a), t(a, '0' + b);
  cout << min(s, t) << endl;

  return 0;
}
