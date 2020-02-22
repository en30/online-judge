#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, R;
  cin >> N >> R;
  int ans = R;
  if (N <= 10) ans += 100 * (10 - N);
  cout << ans << endl;
  return 0;
}
