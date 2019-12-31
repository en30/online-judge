#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> C;
int main() {
  cin >> N;
  C.resize(N);
  rep(i, N) cin >> C[i];

  vector<int> D(N, 0);
  rep(i, N) rep(j, N) {
    if (i == j) continue;
    if (C[i] % C[j] == 0) D[i] += 1;
  }

  vector<double> fact(N + 1, 1);
  rep(i, N) fact[i + 1] = (i + 1) * fact[i];

  double ans = 0;

  auto C = [&](int n, int k) {
    return n - k >= 0 ? fact[n] / fact[n - k] / fact[k] : 0;
  };
  auto P = [&](int n, int k) { return n - k >= 0 ? fact[n] / fact[n - k] : 0; };

  rep(l, N) rep(i, N) {
    for (int k = 0; k <= l && k <= D[i]; k += 2) {
      ans += C(l, k) * P(D[i], k) * P(N - D[i] - 1, l - k) * fact[N - l - 1];
    }
  }

  ans /= fact[N];

  printf("%.7lf\n", ans);
  return 0;
}
