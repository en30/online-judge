#include <bits/stdc++.h>
#include "../include/template"

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll d = c - a - b;
  cout << (d > 0 && 4 * a * b < d * d ? "Yes" : "No") << endl;
  return 0;
}
