#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;
  string ans = "";
  rep(i, s.size()) {
    if (s[i] == 'B') {
      ans = ans.substr(0, ans.size() - 1);
    } else {
      ans = ans + s[i];
    }
  }

  cout << ans << endl;

  return 0;
}
