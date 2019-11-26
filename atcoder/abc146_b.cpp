#include <bits/stdc++.h>
#include "../include/template"

int N;
string S;

int main() {
  cin >> N >> S;

  for (char c : S) {
    char cc = ('A' + (c - 'A' + N) % 26);
    cout << cc;
  }
  cout << endl;
  return 0;
}
