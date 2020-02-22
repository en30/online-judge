#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  cout << ((s.size() % 2) ^ (s[0] == s[s.size() - 1]) ? "First" : "Second")
       << endl;
  return 0;
}
