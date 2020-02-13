#include <bits/stdc++.h>
#include "../include/template"
#include "../include/coordinate_compression.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  CoordinateCompression<int> c(a);
  rep(i, N) cout << c.compress(a[i]) << endl;

  return 0;
}
