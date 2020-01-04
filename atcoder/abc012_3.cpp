#include <bits/stdc++.h>
#include "../include/template"

int N;
int main() {
  cin >> N;

  int M = 0;
  rep(i, 9) rep(j, 9) { M += (i + 1) * (j + 1); }
  M -= N;

  rep(i, 9) rep(j, 9) {
    if ((i + 1) * (j + 1) != M) continue;

    printf("%d x %d\n", i + 1, j + 1);
  }

  return 0;
}
