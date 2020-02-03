#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  int N = s.size();
  rep(i, N) { cout << s[N - 1 - i]; }
  cout << endl;
  return 0;
}
