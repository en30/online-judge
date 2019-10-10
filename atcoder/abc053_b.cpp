#include <bits/stdc++.h>
#include "../include/template"

string s;

int main() {
  cin >> s;

  int a = -1, z = 0;
  rep(i, s.size()) {
    if (s[i] == 'A' && a == -1) a = i;
    if (s[i] == 'Z') z = i;
  }

  cout << z - a + 1 << endl;

  return 0;
}
