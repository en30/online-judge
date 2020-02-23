#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B;
  char op;
  cin >> A >> op >> B;
  cout << (op == '+' ? A + B : A - B) << endl;
  return 0;
}
