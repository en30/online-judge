#include <bits/stdc++.h>
#include "../include/template"

int N, K;

int main() {
  cin >> N >> K;

  double ans = 0.0;
  for (int i = 1; i <= N; ++i) {
    int r = ceil(log2(double(K) / i));
    ans += pow(0.5, max(0, r));
  }

  printf("%.12lf\n", ans / N);

  return 0;
}
