#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int m = A[N - 1];
  vector<int> B(N);
  for (int i = N - 1; i >= 0; --i) {
    B[i] = m - A[i];
    chmax(m, A[i]);
  }

  cout << count(all(B), *max_element(all(B))) << endl;

  return 0;
}
