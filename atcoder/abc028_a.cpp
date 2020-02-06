#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  if (N < 60) {
    cout << "Bad";
  } else if (N < 90) {
    cout << "Good";
  } else if (N < 100) {
    cout << "Great";
  } else {
    cout << "Perfect";
  }
  cout << endl;
  return 0;
}
