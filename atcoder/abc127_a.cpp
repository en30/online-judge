#include <bits/stdc++.h>
#include "../include/template"

int A, B;
int main() {
  cin >> A >> B;

  int ans;
  if (A <= 5) {
    ans = 0;
  } else if (A <= 12) {
    ans = B / 2;
  } else {
    ans = B;
  }

  cout << ans << endl;

  return 0;
}
