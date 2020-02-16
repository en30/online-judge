#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int A;
    cin >> A;
    if (A % 2 == 0 && (A % 3 != 0 && A % 5 != 0)) {
      cout << "DENIED" << endl;
      return 0;
    }
  }

  cout << "APPROVED" << endl;
  return 0;
}
