#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int K, N;
  cin >> K >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];
  rep(i, N) A.push_back(A[i] + K);

  int d = 0;
  rep(i, N) chmax(d, A[i + 1] - A[i]);
  cout << K - d << endl;

  return 0;
}
