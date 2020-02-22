#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> T(N), A(N);
  rep(i, N) cin >> T[i] >> A[i];

  ll t = 1, a = 1;
  rep(i, N) {
    ll r = max((t + T[i] - 1) / T[i], (a + A[i] - 1) / A[i]);
    t = T[i] * r;
    a = A[i] * r;
  }
  cout << t + a << endl;

  return 0;
}
