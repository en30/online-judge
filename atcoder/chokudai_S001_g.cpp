#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  int N;
  cin >> N;

  ModInt ans = 0;
  rep(i, N) {
    int a;
    cin >> a;
    int b = a;
    while (b) {
      ans *= 10;
      b /= 10;
    }
    ans += a;
  }

  cout << ans << endl;
  return 0;
}
