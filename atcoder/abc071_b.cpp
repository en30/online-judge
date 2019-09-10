#include <bits/stdc++.h>
#include "../include/template"

string S;
set<char> s;

int main() {
  cin >> S;

  for (char c = 'a'; c <= 'z'; c += 1) {
    s.insert(c);
  }

  for (char c : S) {
    s.erase(c);
  }

  if (s.size() == 0) {
    cout << "None";
  } else {
    cout << (*s.begin());
  }
  cout << endl;

  return 0;
}
