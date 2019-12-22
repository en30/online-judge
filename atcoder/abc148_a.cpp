#include <bits/stdc++.h>
#include "../include/template"

int A, B;
int main() {
  cin >> A >> B;
  set<int> s = {1, 2, 3};
  s.erase(A);
  s.erase(B);
  cout << *s.begin() << endl;

  return 0;
}
