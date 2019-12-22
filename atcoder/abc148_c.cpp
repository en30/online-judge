#include <bits/stdc++.h>
#include "../include/template"
#include "../include/gcd.hpp"

int A, B;

int main() {
  cin >> A >> B;
  cout << ll(A) * B / gcd(A, B) << endl;
  return 0;
}
