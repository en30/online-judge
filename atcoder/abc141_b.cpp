#include <bits/stdc++.h>
#include "../include/template"

string S;

bool good() {
  for (int i = 0; i < S.size(); ++i) {
    if ((i % 2 == 0 && S[i] == 'L') || (i % 2 == 1 && S[i] == 'R')) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> S;
  cout << (good() ? "Yes" : "No") << endl;
  return 0;
}
