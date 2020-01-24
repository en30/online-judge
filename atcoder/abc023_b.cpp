#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  string a = "b";
  int i = 0;
  while (a.size() < N) {
    ++i;
    if (i % 3 == 0) {
      a = "b" + a + "b";
    } else if (i % 3 == 1) {
      a = "a" + a + "c";
    } else {
      a = "c" + a + "a";
    }
  }

  cout << (S == a ? i : -1) << endl;
  return 0;
}
