#include <bits/stdc++.h>
#include "../include/template"

string S;

int main() {
  cin >> S;

  for (int i = 0; i < S.size(); ++i) {
    char c = S[i];
    if (i == 0) {
      if (c >= 'a') c = (c - 'a') + 'A';
    } else {
      if (c <= 'Z') c = (c - 'A') + 'a';
    }
    cout << c;
  }
  cout << endl;

  return 0;
}
