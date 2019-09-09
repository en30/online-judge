#include <bits/stdc++.h>
#include "../include/template"

int N;
set<int> s;

int main() {
  cin >> N;
  rep(i, N) {
    int A;
    cin >> A;
    if (s.find(A) == s.end()) {
      s.insert(A);
    } else {
      s.erase(A);
    }
  }
  cout << s.size() << endl;
  return 0;
}
