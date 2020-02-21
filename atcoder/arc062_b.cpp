#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;

  const int N = s.size();
  int ans = 0;
  rep(i, N) {
    if (i % 2) {
      ans += (s[i] == 'g' ? 1 : 0);
    } else {
      ans += (s[i] == 'g' ? 0 : -1);
    }
  }

  cout << ans << endl;

  return 0;
}
