#include <bits/stdc++.h>
#include "../include/template"

int X, t;
int main() {
  cin >> X >> t;
  cout << max(X - t, 0) << endl;
  return 0;
}
