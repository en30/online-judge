#include <bits/stdc++.h>
#include "../include/template"

int N;
string s;

int main() {
  cin >> N >> s;

  int ans = 0, x = 0;
  rep(i, N) {
    if (s[i] == 'I') {
      ++x;
    } else {
      --x;
    }
    ans = max(ans, x);
  }

  cout << ans << endl;

  return 0;
}
