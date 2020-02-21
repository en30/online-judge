#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> T(N), A(N);
  rep(i, N) cin >> T[i] >> A[i];

  ll t = T[0], a = A[0];
  for (int i = 1; i < N; ++i) {
    int r = [&]() {
      ll kt = (t + T[i] - 1) / T[i], ka = (a + A[i] - 1) / A[i];
      if (kt * A[i] < a) return ka;
      if (ka * T[i] < t) return kt;
      return min(ka, kt);
    }();
    t = T[i] * r;
    a = A[i] * r;
  }

  cout << t + a << endl;

  return 0;
}
