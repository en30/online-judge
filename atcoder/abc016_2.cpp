#include <bits/stdc++.h>
#include "../include/template"

int A, B, C;
int main() {
  cin >> A >> B >> C;

  if (A + B == C && A - B != C) {
    cout << "+" << endl;
  } else if (A + B != C && A - B == C) {
    cout << "-" << endl;
  } else if (A + B == C || A - B == C) {
    cout << "?" << endl;
  } else {
    cout << "!" << endl;
  }

  return 0;
}
