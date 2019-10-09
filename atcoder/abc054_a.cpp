#include <bits/stdc++.h>
#include "../include/template"

int A, B;

int main() {
  cin >> A >> B;

  if (A == 1) A += 13;
  if (B == 1) B += 13;

  if (A > B) {
    cout << "Alice";
  } else if (A < B) {
    cout << "Bob";
  } else {
    cout << "Draw";
  }

  cout << endl;
  return 0;
}
