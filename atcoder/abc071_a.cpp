#include <bits/stdc++.h>
#include "../include/template"

int x, a, b;
int main() {
  cin >> x >> a >> b;

  if (abs(x - a) < abs(x - b)) {
    cout << "A";
  } else {
    cout << "B";
  }
  cout << endl;
  return 0;
}
