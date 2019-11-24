#include <bits/stdc++.h>
#include "../include/template"

int N;

int main() {
  cin >> N;

  double p = double((N + 1) / 2) / N;
  printf("%.10lf\n", p);
  return 0;
}
