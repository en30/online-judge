#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;

  int ans = 0;
  char g = '0';
  rep(i, N) {
    char c;
    cin >> c;
    if (c != g) {
      ans++;
      g = c;
    }
  }

  cout << ans << endl;
  return 0;
}
