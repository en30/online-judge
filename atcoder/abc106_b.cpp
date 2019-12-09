#include <bits/stdc++.h>
#include "../include/template"
#include "../include/prime.hpp"

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i += 2) {
    int n = 1;
    for (auto pf : Prime::factorize(i)) n *= (pf.r + 1);
    if (n == 8) ans++;
  }

  cout << ans << endl;

  return 0;
}
