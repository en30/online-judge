#include <bits/stdc++.h>
#include "../include/template"
#include "../include/knuth_morris_pratt.hpp"

int N;

int main() {
  cin >> N;
  vector<int> a(N), b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];

  vector<int> c(2 * N), d(N);
  rep(i, N) {
    c[i] = a[i] ^ a[(i + 1) % N];
    c[i + N] = c[i];
    d[i] = b[i] ^ b[(i + 1) % N];
  }

  KnuthMorrisPratt<vector<int>> kmp(d);

  for (int k : kmp.matchedIndices(c)) {
    if (k >= N) continue;
    int x = b[0] ^ a[k];
    cout << k << " " << x << endl;
  }

  return 0;
}
