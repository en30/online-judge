#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int X;
  cin >> X;
  cout << (X / 500) * 1000 + ((X % 500) / 5) * 5 << endl;
  return 0;
}
