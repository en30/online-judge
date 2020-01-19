#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<unordered_map<int, int>> B(N);
  unordered_map<int, int> lcm;
  rep(j, N) {
    int m = A[j];
    for (int i = 2; i * i <= m; i++) {
      if (m % i) continue;
      int r = 0;
      while (m % i == 0) {
        m /= i;
        r++;
      }
      B[j][i] = r;
      lcm[i] = max(lcm[i], r);
    }
    if (m != 1) {
      B[j][m] = 1;
      lcm[m] = max(lcm[m], 1);
    }
  }

  ModInt m = 1;
  for (auto it = lcm.begin(); it != lcm.end(); it++) {
    m *= ModInt(it->first).pow(it->second);
  }

  ModInt ans = 0;
  rep(i, N) ans += m / A[i];

  cout << ans << endl;

  return 0;
}
