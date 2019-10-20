#include <bits/stdc++.h>
#include "../include/template"

int A, B;

int main() {
  cin >> A >> B;

  cout << max(0, A - B * 2) << endl;
  return 0;
}
