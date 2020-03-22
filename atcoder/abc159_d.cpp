#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, ll> C;
  rep(i, N) {
    cin >> A[i];
    ++C[A[i]];
  }

  ll S = 0;
  for (auto& p : C) {
    S += p.second * (p.second - 1) / 2;
  }

  rep(k, N) {
    ll m = C[A[k]];
    cout << S - m * (m - 1) / 2 + (m - 1) * (m - 2) / 2 << endl;
  }

  return 0;
}
