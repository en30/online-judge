#include <bits/stdc++.h>
#include "../include/template"

int main() {
  set<char> s;
  rep(i, 4) {
    char c;
    cin >> c;
    s.insert(c);
  }

  cout << (s.size() == 1 ? "SAME" : "DIFFERENT") << endl;
  return 0;
}
