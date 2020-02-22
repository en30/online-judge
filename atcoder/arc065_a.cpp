#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  reverse(all(S));

  vector<string> pats = {"dream", "erase", "eraser", "dreamer"};
  for (string& s : pats) reverse(all(s));

  auto head = [&](int i, const string& s) {
    int m = s.size();
    if (i + m > S.size()) return false;
    return S.substr(i, m) == s;
  };

  auto good = [&]() {
    for (int i = 0; i < S.size();) {
      for (string& s : pats) {
        if (head(i, s)) {
          i += s.size();
          goto HOGE;
        }
      }
      return false;
    HOGE:;
    }
    return true;
  };

  cout << (good() ? "YES" : "NO") << endl;
  return 0;
}
