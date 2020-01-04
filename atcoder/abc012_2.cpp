#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;

  int h = N / 3600;
  int m = (N % 3600) / 60;
  int s = N - 3600 * h - 60 * m;
  printf("%02d:%02d:%02d\n", h, m, s);
  return 0;
}
