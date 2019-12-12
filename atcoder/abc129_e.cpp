#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

using mint = ModInt;

string L;

mint p(int x, int d) {
  if (d == 0) return 1;
  mint res = 1;
  if (d % 2 != 0) res = x;
  mint r = p(x, d / 2);
  return r * r * res;
}

int main() {
  cin >> L;

  int N = L.size();

  mint ans = 0;
  int c = 0;
  rep(i, N) if (L[i] == '1') {
    ans += p(2, c) * p(3, N - i - 1);
    c++;
  }

  // L
  ans += p(2, c);

  cout << ans << endl;

  return 0;
}
