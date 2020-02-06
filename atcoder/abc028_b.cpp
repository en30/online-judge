#include <bits/stdc++.h>
#include "../include/template"

int main() {
  map<char, int> C;
  rep(i, 6) C['A' + i] = 0;
  string S;
  cin >> S;
  for (char c : S) C[c] += 1;

  for (auto it = C.begin(); it != C.end(); ++it) {
    if (it != C.begin()) cout << " ";
    cout << it->second;
  }
  cout << endl;

  return 0;
}
