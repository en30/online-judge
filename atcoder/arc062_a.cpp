#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> T(N), A(N);
  rep(i, N) cin >> T[i] >> A[i];

  ll t = T[0], a = A[0];
  for (int i = 1; i < N; ++i) {
    ll kt = (t + T[i] - 1) / T[i], ka = (a + A[i] - 1) / A[i];
    if (kt * A[i] < a) {
      t = T[i] * ka;
      a = A[i] * ka;
      continue;
    }
    if (ka * T[i] < t) {
      t = T[i] * kt;
      a = A[i] * kt;
      continue;
    }
    t = T[i] * min(ka, kt);
    a = A[i] * min(ka, kt);
  }

  cout << t + a << endl;

  return 0;
}
