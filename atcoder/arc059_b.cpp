#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;

  int N = s.size();
  rep(i, N) {
    if (i + 1 < N && s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }

    if (i + 2 < N && s[i] == s[i + 2]) {
      cout << i + 1 << " " << i + 3 << endl;
      return 0;
    }
  }

  cout << -1 << " " << -1 << endl;
  return 0;
}
