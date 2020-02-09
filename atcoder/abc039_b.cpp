#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int X;
  cin >> X;
  for (int i = 1; i <= X; ++i) {
    if (i * i * i * i == X) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
