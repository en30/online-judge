#include <bits/stdc++.h>
#include "../include/template"

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  cout << (a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0] ? "YES" : "NO")
       << endl;
  return 0;
}
