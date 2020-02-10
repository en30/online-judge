#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  int k;
  cin >> s >> k;

  set<string> cands;
  for (int i = 0; i + k - 1 < s.size(); ++i) {
    cands.insert(s.substr(i, k));
  }
  cout << cands.size() << endl;
  return 0;
}
