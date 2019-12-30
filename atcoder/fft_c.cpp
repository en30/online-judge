#include <bits/stdc++.h>
#include "../include/template"
#include "../include/convolution.hpp"

int N;
vector<int> A, B;

int main() {
  cin >> N;
  A.resize(N + 1, 0), B.resize(N + 1, 0);
  rep(i, N) cin >> A[i + 1] >> B[i + 1];

  Convolution conv(A, B);
  for (int i = 1; i <= 2 * N; ++i) {
    cout << conv[i] << endl;
  }

  return 0;
}
