#include <bits/stdc++.h>
#include "../include/template"

string S, T;

int main() {
  cin >> S >> T;

  bool canWin = true;
  string U = "atcoder";
  rep(i, S.size()) {
    if (!((S[i] == '@' && (U.find(T[i]) != string::npos)) || S[i] == T[i] ||
          (T[i] == '@' && (U.find(S[i]) != string::npos)))) {
      canWin = false;
    }
  }
  if (canWin) {
    cout << "You can win";
  } else {
    cout << "You will lose";
  }
  cout << endl;

  return 0;
}
