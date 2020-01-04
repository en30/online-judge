#include <bits/stdc++.h>
#include "../include/template"

int N, D, X, Y;
int main() {
  cin >> N >> D >> X >> Y;

  if (X % D != 0 || Y % D != 0) {
    cout << 0 << endl;
    return 0;
  }

  X = abs(X / D);
  Y = abs(Y / D);

  // nCk / 2^n;
  vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1));
  function<double(int, int)> prob = [&](int n, int k) {
    if (memo[n][k] != -1) return memo[n][k];
    if (n == 0 || k == 0 || k == n) return pow(2.0, -n);
    return memo[n][k] = (prob(n - 1, k - 1) + prob(n - 1, k)) / 2.0;
  };

  double p = 0;
  rep(h, N + 1) {
    if ((X + h) % 2 != 0) continue;
    int r = (X + h) / 2;
    if (h - r < 0) continue;

    if ((Y + (N - h)) % 2 != 0) continue;
    int u = (Y + (N - h)) / 2;
    if (N - h - u < 0) continue;

    p += prob(N, h) * prob(h, r) * prob(N - h, u);
  }

  printf("%.10lf\n", p);

  return 0;
}
