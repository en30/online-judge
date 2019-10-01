#include <bits/stdc++.h>
#include "../include/template"

int A, B, C;
int main() {
  cin >> A >> B >> C;
  bool yes = false;
  rep(i, B) {
    if (((i + 1) * A) % B == C) yes = true;
  }
  cout << (yes ? "YES" : "NO") << endl;
  return 0;
}
