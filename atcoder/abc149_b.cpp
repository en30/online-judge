#include <bits/stdc++.h>
#include "../include/template"

ll A, B, K;

int main() {
  cin >> A >> B >> K;

  ll d = min(A, K);
  A -= d;
  K -= d;
  B -= min(B, K);
  cout << A << " " << B << endl;
  return 0;
}
