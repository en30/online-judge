#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  rep(i, 6) {
    if (i) cout << " ";
    cout << count(all(S), 'A' + i);
  }
  cout << endl;
  return 0;
}
