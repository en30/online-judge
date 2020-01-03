#include <bits/stdc++.h>
#include "../include/template"

int N;
vector<int> A;

int main() {
  cin >> N;
  A.resize(N);
  rep(i, N) cin >> A[i];

  rep(i, N - 1) {
    if (A[i + 1] - A[i] == 0) {
      cout << "stay";
    } else if (A[i + 1] - A[i] > 0) {
      cout << "up " << A[i + 1] - A[i];
    } else {
      cout << "down " << -A[i + 1] + A[i];
    }
    cout << endl;
  }

  return 0;
}
