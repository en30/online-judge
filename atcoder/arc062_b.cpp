#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string s;
  cin >> s;

  const int N = s.size();
  const int P = count(all(s), 'p');
  cout << N / 2 - P << endl;

  return 0;
}
