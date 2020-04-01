#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int k;
  cin >> k;

  int d;
  for (int i = 30; i >= 0; --i) {
    if ((k >> i) & 1) {
      d = i;
      break;
    }
  }

  int mask = (1 << (d + 2)) - 1;
  int f = (1 << (d + 1));
  printf("3 3\n");
  printf("%d %d %d\n", mask, k, 0);
  printf("%d %d %d\n", f, mask, k);
  printf("%d %d %d\n", 0, k, k);

  return 0;
}
