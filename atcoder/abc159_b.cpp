#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  const int N = S.size();

  auto f = [](string s) {
    int n = s.size();
    rep(i, n) if (s[i] != s[n - 1 - i]) return false;
    return true;
  };

  if (f(S) && f(S.substr(0, (N - 1) / 2)) && f(S.substr((N + 3) / 2 - 1))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
