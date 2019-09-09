#include <bits/stdc++.h>
#include "../include/template"

string s;

int main() {
  cin >> s;
  int N = s.size();
  rep(i, N) {
    if (i % 2 == 0) cout << s[i];
  }
  cout << endl;

  return 0;
}
