#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  if (count(all(s), 'A') % 3 == 0) {
    cout << "No";
  } else {
    cout << "Yes";
  }
  cout << endl;
  return 0;
}
