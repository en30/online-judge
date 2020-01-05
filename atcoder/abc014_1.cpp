#include <bits/stdc++.h>
#include "../include/template"

int a, b;

int main() {
  cin >> a >> b;
  cout << (b - a % b) % b << endl;
  return 0;
}
