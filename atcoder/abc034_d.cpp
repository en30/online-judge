#include <bits/stdc++.h>
#include "../include/template"

struct Bin {
  int w, p;

  double f(double k) { return (p - k) / 100.0 * w; }
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<Bin> bins(N);
  rep(i, N) cin >> bins[i].w >> bins[i].p;

  auto achievable = [&](double p) {
    vector<double> f(N);
    rep(i, N) f[i] = bins[i].f(p);
    sort(f.rbegin(), f.rend());
    int i = 0;
    double s = 0.0;
    while (i < N && s + f[i] >= 0.0) s += f[i++];
    return i >= K;
  };

  double l = 0, r = 100.1;
  rep(i, 200) {
    double m = (l + r) / 2.0;
    if (achievable(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  printf("%.10lf\n", l);

  return 0;
}
