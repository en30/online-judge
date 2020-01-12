#include <bits/stdc++.h>
#include "../include/template"

int main() {
  int N, K, M;
  cin >> N >> K >> M;
  vector<int> A(N - 1);
  int sum = 0;
  rep(i, N - 1) {
    cin >> A[i];
    sum += A[i];
  }
  int d = M * N - sum;
  if (d > K) {
    cout << -1 << endl;
  } else {
    cout << max(d, 0) << endl;
  }
  return 0;
}
