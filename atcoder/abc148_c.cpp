#include <bits/stdc++.h>
#include "../include/template"

int A, B;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  cin >> A >> B;
  cout << ll(A) * B / gcd(A, B) << endl;
  return 0;
}
