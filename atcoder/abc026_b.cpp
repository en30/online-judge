#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;

  vector<int> R(N);
  rep(i, N) cin >> R[i];
  sort(R.rbegin(), R.rend());

  double ans = 0;
  rep(i, N) {
    double s = R[i] * R[i];
    if (i % 2) s = -s;
    ans += s;
  }
  ans *= M_PI;

  printf("%.7lf\n", ans);
  return 0;
}
