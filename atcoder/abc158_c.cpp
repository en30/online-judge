#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B;
  cin >> A >> B;

  for (int x = 1; x <= 1000; ++x) {
    if (floor(x * 0.08) == A && floor(x * 0.10) == B) {
      cout << x << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
