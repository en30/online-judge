#include <bits/stdc++.h>
#include "../include/template"

int main() {
  set<char> s = {'a', 'e', 'i', 'o', 'u'};
  char c;
  cin >> c;
  cout << (s.find(c) == s.end() ? "consonant" : "vowel") << endl;
  return 0;
}
