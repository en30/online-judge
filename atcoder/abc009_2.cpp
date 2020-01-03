#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;
  set<int> s;
  rep(i, N) {
    int A;
    cin >> A;
    s.insert(A);
  }

  cout << *prev(s.end(), 2) << endl;
  return 0;
}
