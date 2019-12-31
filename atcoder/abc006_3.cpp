#include <bits/stdc++.h>
#include "../include/template"

int N, M;

int main() {
  cin >> N >> M;
  rep(x, N + 1) {
    int z = (M - 2 * x) - 3 * (N - x);
    int y = N - x - z;
    if (y < 0 || z < 0) continue;
    printf("%d %d %d\n", x, y, z);
    return 0;
  }
  printf("%d %d %d\n", -1, -1, -1);
  return 0;
}
