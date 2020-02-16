#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> c(N, 1e18);
  c[N - 1] = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (i - 1 >= 0) chmin(c[i - 1], c[i] + abs(a[i] - a[i - 1]));
    if (i - 2 >= 0) chmin(c[i - 2], c[i] + abs(a[i] - a[i - 2]));
  }
  cout << c[0] << endl;

  return 0;
}
