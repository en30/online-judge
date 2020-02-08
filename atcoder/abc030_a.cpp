#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if (B * C - A * D == 0) {
    cout << "DRAW";
  } else if (B * C - A * D < 0) {
    cout << "AOKI";
  } else {
    cout << "TAKAHASHI";
  }
  cout << endl;
  return 0;
}
