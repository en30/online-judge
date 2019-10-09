#include <bits/stdc++.h>
#include "../include/template"

int A, B;

int main() {
  cin >> A >> B;

  if (A == B) {
    cout << "Draw";
  } else if (A == 1) {
    cout << "Alice";
  } else if (B == 1) {
    cout << "Bob";
  } else if (A > B) {
    cout << "Alice";
  } else {
    cout << "Bob";
  }

  cout << endl;
  return 0;
}
