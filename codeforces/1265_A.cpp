#include <bits/stdc++.h>
#include "../include/template"

int N;

int mask(char c) {
  if (c == '?') return 0;
  return 1 << (c - 'a');
}

string solve(string& s) {
  string res(s);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '?') {
      if (i > 0 && s[i] == s[i - 1]) return "-1";
      if (i < s.size() - 1 && s[i] == s[i + 1]) return "-1";
      continue;
    }

    int m = 0;
    if (i > 0) m = mask(res[i - 1]);
    if (i < s.size() - 1) m |= mask(res[i + 1]);
    rep(j, 3) {
      if (!((m >> j) & 1)) {
        res[i] = char('a' + j);
        break;
      }
    }
  }
  return res;
}

int main() {
  cin >> N;

  rep(i, N) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }

  return 0;
}
