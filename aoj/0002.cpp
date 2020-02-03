#include <bits/stdc++.h>
#include "../include/template"

int digits(int n) {
  if (n == 0) return 0;
  return 1 + digits(n / 10);
}

int main() {
  int a, b;
  while (cin >> a) {
    cin >> b;
    cout << digits(a + b) << endl;
  }
  return 0;
}
