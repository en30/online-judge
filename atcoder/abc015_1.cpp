#include <bits/stdc++.h>
#include "../include/template"

string A, B;

int main() {
  cin >> A >> B;
  cout << (A.size() > B.size() ? A : B) << endl;
  return 0;
}
