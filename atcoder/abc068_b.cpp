#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;

  int ans;
  for (int i = 6; i >= 0; --i) {
    if ((N >> i) & 1) {
      ans = 1 << i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
