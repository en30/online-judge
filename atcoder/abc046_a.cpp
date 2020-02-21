#include <bits/stdc++.h>
#include "../include/template"

int main() {
  set<int> s;
  rep(i, 3) {
    int a;
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << endl;

  return 0;
}
