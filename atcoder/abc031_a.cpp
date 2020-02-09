#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, D;
  cin >> A >> D;
  if (D > A) {
    ++A;
  } else {
    ++D;
  }
  cout << A * D << endl;
  return 0;
}
