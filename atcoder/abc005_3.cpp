#include <bits/stdc++.h>
#include "../include/template"

int N, T, M;
vector<int> A, B;

int main() {
  cin >> T >> N;

  A.resize(N);
  rep(i, N) cin >> A[i];

  cin >> M;
  B.resize(M);
  rep(i, M) cin >> B[i];

  vector<bool> used(N, false);
  rep(i, M) {
    bool found = false;
    rep(j, N) {
      if (!used[j] && A[j] <= B[i] && B[i] <= A[j] + T) {
        found = true;
        used[j] = true;
        break;
      }
    }
    if (!found) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;

  return 0;
}
