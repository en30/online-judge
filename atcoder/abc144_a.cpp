#include <bits/stdc++.h>
#include "../include/template"

int A, B;

int main() {
  cin >> A >> B;

  cout << ((A <= 9 && B <= 9) ? A * B : -1) << endl;
  return 0;
}
