#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  for (char c : s) {
    if (count(all(s), c) % 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
