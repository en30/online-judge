#include <bits/stdc++.h>
#include "../include/template"
#include "../include/mod.hpp"
#include "../include/matrix.hpp"

using mint = ModInt;

int N;
ll K;
vector<vector<int>> a;

int main() {
  cin >> N >> K;
  a.resize(N, vector<int>(N));

  Matrix<mint> R(N, N);
  cin >> R;
  R = R.power(K);

  mint ans = 0;
  rep(i, N) rep(j, N) ans += R[i][j];
  cout << ans << endl;
  return 0;
}
