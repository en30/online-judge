#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  set<int> s;
  s.insert(A);
  s.insert(B);
  s.insert(C);
  cout << (s.size() == 2 ? "Yes" : "No") << endl;
  return 0;
}
