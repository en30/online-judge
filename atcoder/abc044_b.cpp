#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  map<char, int> c;
  rep(i, s.size()) c[s[i]] += 1;

  for (auto& p : c) {
    if (p.second % 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
