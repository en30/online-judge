#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "../include/template"

using F = boost::multiprecision::cpp_dec_float_100;

int N, D, X, Y;
int main() {
  cin >> N >> D >> X >> Y;

  if (X < 0) X = -X;
  if (Y < 0) Y = -Y;

  int k = (N - X / D - Y / D);
  if (X % D != 0 || Y % D != 0 || k % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  k /= 2;

  vector<F> fact(N + 1);
  fact[0] = F("1");
  rep(i, N) fact[i + 1] = F(to_string(i + 1)) * fact[i];

  F p("0");
  rep(l, k + 1) {
    int d = k - l;
    int r = l + X / D;
    int u = d + Y / D;

    p += fact[N] / fact[l] / fact[d] / fact[r] / fact[u];
  }

  p /= pow(F("4"), N);

  cout << p << endl;

  return 0;
}
