#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string S;
  cin >> S;
  int T;
  cin >> T;

  int x = 0, y = 0, u = 0;
  for (char c : S) {
    if (c == 'L') {
      --x;
    } else if (c == 'R') {
      ++x;
    } else if (c == 'U') {
      ++y;
    } else if (c == 'D') {
      --y;
    } else {
      ++u;
    }
  }

  int d = abs(x) + abs(y);
  if (T == 1) {
    cout << d + u << endl;
  } else {
    cout << (d >= u ? d - u : (u - d) % 2) << endl;
  }

  return 0;
}
