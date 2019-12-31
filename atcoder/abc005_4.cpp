#include <bits/stdc++.h>
#include "../include/template"
#include "../include/cummulative_sum_2d.hpp"

int N, Q;
vector<vector<int>> D;

int main() {
  cin >> N;
  D.resize(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> D[i][j];

  CummulativeSum2D<int> cumsum(D);

  vector<int> T(N * N + 1, 0);
  rep(i, N) rep(j, N) rep(k, N) rep(l, N) {
    if (i > k || j > l) continue;
    int s = (k - i + 1) * (l - j + 1);
    T[s] = max(T[s], cumsum.query(i, j, k + 1, l + 1));
  }

  cin >> Q;

  rep(i, Q) {
    int P;
    cin >> P;
    cout << *max_element(T.begin(), T.begin() + P + 1) << endl;
  }

  return 0;
}
