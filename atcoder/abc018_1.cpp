#include <bits/stdc++.h>
#include "../include/template"

int main() {
  vector<int> s(3), t(3);
  rep(i, 3) {
    cin >> s[i];
    t[i] = s[i];
  }
  sort(s.rbegin(), s.rend());

  rep(i, 3) cout << distance(s.begin(), find(all(s), t[i])) + 1 << endl;

  return 0;
}
