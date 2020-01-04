#include <bits/stdc++.h>
#include "../include/template"

int a, b;
int main() {
  cin >> a >> b;

  if (b < a) swap(a, b);
  cout << min(b - a, 10 - b + a) << endl;
  return 0;
}
