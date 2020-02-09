#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0;
  double e = 0;
  vector<double> p(N);
  rep(i, N) cin >> p[i];

  rep(i, N) {
    e += (1.0 + p[i]) / 2;
    if (i >= K) e -= (1.0 + p[i - K]) / 2;
    chmax(ans, e);
  }

  printf("%.10lf\n", ans);
  return 0;
}
