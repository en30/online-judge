#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  double ans = (3.0 * 2 * (K - 1) * (N - K) + 3 * (N - 1) + 1) / N / N / N;
  printf("%.20lf\n", ans);
  return 0;
}
