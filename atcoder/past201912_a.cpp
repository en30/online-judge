#include <bits/stdc++.h>
#include "../include/template"

string S;

int main() {
  cin >> S;

  bool err = false;
  rep(i, S.size()) { err |= S[i] < '0' || S[i] > '9'; }

  if (err) {
    cout << "error" << endl;
  } else {
    cout << 2 * stoi(S) << endl;
  }
  return 0;
}
