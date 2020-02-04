#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  vector<int> R(N + 1, 0);
  rep(i, N) cin >> R[i + 1];
  sort(all(R));

  double ans = 0;
  rep(i, N) {
    if ((N - i) % 2) ans += R[i + 1] * R[i + 1] - R[i] * R[i];
  }
  ans *= M_PI;

  printf("%.7lf\n", ans);
  return 0;
}
