#include <bits/stdc++.h>
#include "../include/template"

string X;

bool isChokugo(string s) {
  if (s == "") return true;
  if (s[0] == 'c' && s[1] == 'h') return isChokugo(s.substr(2));
  if (s[0] == 'o' || s[0] == 'k' || s[0] == 'u') return isChokugo(s.substr(1));
  return false;
}

int main() {
  cin >> X;

  cout << (isChokugo(X) ? "YES" : "NO") << endl;
  return 0;
}
