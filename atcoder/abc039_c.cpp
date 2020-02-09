#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  string T = "WBWBWWBWBWBW";
  int M = T.size();
  vector<string> notes = {"Do", "Do", "Re", "Re", "Mi", "Fa",
                          "Fa", "So", "So", "La", "La", "Si"};
  rep(i, 4) T = T + T;

  int i = T.find(S);
  cout << notes[i % M] << endl;

  return 0;
}
