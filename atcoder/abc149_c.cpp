#include <bits/stdc++.h>
#include "../include/template"

bool isPrime(int e) {
  for (int i = 2; i <= (int)sqrt(e); i++) {
    if (e % i == 0) return false;
  }
  return true;
}

int X;

int main() {
  cin >> X;
  for (int i = X;; ++i) {
    if (isPrime(i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
