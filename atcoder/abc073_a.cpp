#include <bits/stdc++.h>
#include "../include/template"

string N;
int main() {
  cin >> N;

  cout << (N[0] == '9' || N[1] == '9' ? "Yes" : "No") << endl;
  return 0;
}
