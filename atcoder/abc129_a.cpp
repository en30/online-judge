#include <bits/stdc++.h>
#include "../include/template"

int P, Q, R;
int main() {
  cin >> P >> Q >> R;

  int ans = min(P + Q, min(Q + R, R + P));
  cout << ans << endl;
  return 0;
}
