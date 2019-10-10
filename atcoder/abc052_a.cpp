#include <bits/stdc++.h>
#include "../include/template"

int A, B, C, D;
int main() {
  cin >> A >> B >> C >> D;

  cout << max(A * B, C * D) << endl;
  return 0;
}
