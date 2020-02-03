#include <bits/stdc++.h>
#include "../include/template"
#include "../include/gcd.hpp"

int main() {
  ll a, b;
  while (true) {
    cin >> a >> b;
    if (cin.eof()) break;
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
  return 0;
}
